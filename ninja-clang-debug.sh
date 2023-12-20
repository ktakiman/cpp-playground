#!/bin/bash

#set -x
set -e

rm -rf ninja-clang-debug
mkdir ninja-clang-debug
cd ninja-clang-debug

CC=clang CXX=/clang++ cmake -G Ninja -D CMAKE_EXPORT_COMPILE_COMMANDS=ON -D CMAKE_BUILD_TYPE=Debug ..

cmake --build .

