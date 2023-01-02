# $ cmake -G Ninja -D CMAKE_CXX_COMPILER=clang++ -D CMAKE_EXPORT_COMPILE_COMMANDS=ON

cmake_minimum_required(VERSION 3.12)

project(CppPlayground)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# generates 'compile_commands.json' file
set(CMAKE_EXPORT_COMPILE_COMMANDS True)

# file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "src/*.cxx")
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cxx")

add_executable(playground ${SOURCES})
