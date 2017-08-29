#!/bin/bash

rm -rf build/
mkdir build
cd build
cmake ..
make
# ctest # if one does not too much information
ctest --extra-verbose
