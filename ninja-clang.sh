#!/bin/bash

#set -x
set -e

export CC=/usr/bin/clang
export CXX=/usr/bin/clang++

echo "CC is set to: $CC"
echo "CXX is set to: $CXX"

rm ninja-clang -r
mkdir ninja-clang
cd ninja-clang

cmake -G Ninja ..

cmake --build .
