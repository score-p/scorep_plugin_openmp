# Score-P OpenMP tuning plugin

## Compilation and Installation

### Prerequisites

To compile this plugin, you need:

* C compiler

* `libpthread`

* Score-P

### Building

1. Create build directory

        mkdir build
        cd build

2. Invoke CMake

        cmake ..

2. Invoke make

        make

3. Copy it to a location listed in `LD_LIBRARY_PATH` or add current path to `LD_LIBRARY_PATH` with

        export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:`pwd`

## Usage

This tuning plugin is used during runtime by sending tuning commands over the online access interface of Score-P. Normally, this plugin is used together
with Periscope (http://periscope.in.tum.de/).

### If anything fails

Contact one of the authors.

## Authors

* Robert Mijaković <mijakovi@in.tum.de>
* Michael Firbach <firbach@in.tum.de>
