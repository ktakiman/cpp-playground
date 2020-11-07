cmake_minimum_required(VERSION 3.1)

project(CppPlayground)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")

add_executable(playground 
  ${SOURCE_DIR}/main.cxx
  ${SOURCE_DIR}/env_check.cxx
)


