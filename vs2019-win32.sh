#!/bin/bash

#set -x
set -e

rm -rf vs2019-win32
mkdir vs2019-win32
cd vs2019-win32

cmake -G "Visual Studio 16 2019" -A "Win32" ..

cmake --build .


