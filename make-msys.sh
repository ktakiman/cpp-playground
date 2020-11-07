#!/bin/bash

#set -x
set -e

rm -rf make-msys
mkdir make-msys
cd make-msys

cmake -G "MSYS Makefiles" ..

cmake --build .


