#!/bin/bash

#set -x
set -e

rm ninja-gcc -r
mkdir ninja-gcc
cd ninja-gcc

cmake -G Ninja ..

cmake --build .

