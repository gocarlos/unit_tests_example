#!/bin/bash

rm -rf build/*
mkdir build
cd build
cmake ..
make
./unit_test	% unit test
