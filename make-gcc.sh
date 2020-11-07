#!/bin/bash

#set -x
set -e

rm -rf make-gcc
mkdir make-gcc
cd make-gcc

cmake ..

cmake --build .


