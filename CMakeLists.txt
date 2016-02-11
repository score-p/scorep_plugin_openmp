project(OpenMPTP)

cmake_minimum_required(VERSION 2.8)

#additional c flags
set(CMAKE_C_FLAGS "-D_GNU_SOURCE -g -std=gnu99")

#debugging c flags
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0 -Wstrict-prototypes -Wall -Wundef -Wno-long-long -Wsign-compare -Wcomment -pedantic -finline-functions -fno-strict-aliasing")
set(CMAKE_C_FLAGS_RELEASE "-Os")

include(../scorep_plugin_common/FindScorep.cmake)
if(SCOREP_FOUND)
    include_directories(${SCOREP_INCLUDE_DIRS})    
    link_directories(${SCOREP_LIBRARY_DIRS})
    SET(CMAKE_INSTALL_PREFIX ${SCOREP_ROOT_PATH} CACHE PATH "Install path prefix, prepended onto install directories." FORCE)
else()
    message(SEND_ERROR "Scorep was not found but is required!")
endif()

link_directories(${CMAKE_SOURCE_DIR})

add_library(OpenMPTP SHARED OpenMPTP.c)

install(TARGETS OpenMPTP LIBRARY DESTINATION ${SCOREP_ROOT_PATH}/lib/plugins)

message ("SCOREP_FOUND          =${SCOREP_FOUND}")
message ("SCOREP_ROOT_PATH      =${SCOREP_ROOT_PATH}")
message ("SCOREP_INCLUDE_DIRS   =${SCOREP_INCLUDE_DIRS}")
message ("SCOREP_LIBRARY_DIRS   =${SCOREP_LIBRARY_DIRS}")
message ("CMAKE_C_FLAGS         =${CMAKE_C_FLAGS}")
message ("CMAKE_C_FLAGS_DEBUG   =${CMAKE_C_FLAGS_DEBUG}")
message ("CMAKE_C_FLAGS_RELEASE =${CMAKE_C_FLAGS_RELEASE}")
message ("CMAKE_INSTALL_PREFIX  =${CMAKE_INSTALL_PREFIX}")
message ("CMAKE_SOURCE_DIR      =${CMAKE_SOURCE_DIR}")
