/*
 * This file is part of the Score-P software (http://www.score-p.org)
 *
 * Copyright (c) 2015, Technische Universität München, Germany
 *
 * This software may be modified and distributed under the terms of
 * a BSD-style license.  See the COPYING file in the package base
 * directory for details.
 *
 *
 * INFO:
 *
 * This tuning plugin for Score-P allows the the number of threads in
 * an OpenMP parallel region to be adjusted during run-time.
 *
 */

#include <scorep/SCOREP_TuningPlugins.h>
#include <scorep/SCOREP_TuningTypes.h>
#include <omp.h>
#include <stdio.h>




static void scorep_omp_set_num_threads(int new_setting, int* old_setting) {
    (*old_setting) = omp_get_max_threads();
    omp_set_num_threads(new_setting);
}


static SCOREP_Tuning_Action_Info return_values[] = {
    {
        .name = "NUMTHREADS",
        .kind = SCOREP_TUNING_FUNCTION,
        .enterRegionVariablePtr = NULL,
        .exitRegionVariablePtr = NULL,
        .enterRegionFunctionPtr = &scorep_omp_set_num_threads,
        .exitRegionFunctionPtr = &scorep_omp_set_num_threads,
        .validationEndRegionFunctionPtr = NULL,
        .restoreValueFlag = 1,
        .languageType = 0
    },
    {
        .name = NULL,
        .kind = SCOREP_TUNING_UNDEFINED,
        .enterRegionVariablePtr = NULL,
        .exitRegionVariablePtr = NULL,
        .enterRegionFunctionPtr = NULL,
        .exitRegionFunctionPtr = NULL,
        .validationEndRegionFunctionPtr = NULL,
        .restoreValueFlag = 0,
        .languageType = 0
    }
};


int32_t init() {
    printf("OpenMP tuning plugin: initializing\n");
    return 0;
}


SCOREP_Tuning_Action_Info* get_tuning_info() {
    return return_values;
}


void fini() {
    printf("OpenMP tuning plugin: finalizing\n");
}


SCOREP_TUNING_PLUGIN_ENTRY( OpenMPTP) {
    /* Initialize info data (with zero) */
    SCOREP_Tuning_Plugin_Info info;
    memset(&info, 0, sizeof(SCOREP_Tuning_Plugin_Info));

    /* Set up */
    info.plugin_version = SCOREP_TUNING_PLUGIN_VERSION;
    info.initialize = init;
    info.get_tuning_info = get_tuning_info;
    info.finalize = fini;
    return info;
}
