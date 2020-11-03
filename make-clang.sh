#!/bin/bash

#set -x
set -e

export CC=/usr/bin/clang
export CXX=/usr/bin/clang++

echo "CC is set to: $CC"
echo "CXX is set to: $CXX"

rm make-clang -rf
mkdir make-clang
cd make-clang

cmake ..

cmake --build .

