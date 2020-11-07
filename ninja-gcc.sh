#!/bin/bash

#set -x
set -e

rm -rf ninja-gcc
mkdir ninja-gcc
cd ninja-gcc

cmake -G Ninja ..

cmake --build .

