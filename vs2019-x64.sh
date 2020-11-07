#!/bin/bash

#set -x
set -e

rm -rf vs2019-x64
mkdir vs2019-x64
cd vs2019-x64

cmake -G "Visual Studio 16 2019" -A "x64" ..

cmake --build .


