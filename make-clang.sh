#!/bin/bash

#set -x
set -e

export CC=/usr/bin/clang
export CXX=/usr/bin/clang++

echo "CC is set to: $CC"
echo "CXX is set to: $CXX"

rm -rf make-clang 
mkdir make-clang
cd make-clang

cmake ..

cmake --build .

