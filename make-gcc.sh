#!/bin/bash

#set -x
set -e

rm make-gcc -r
mkdir make-gcc
cd make-gcc

cmake ..

cmake --build .


