cmake_minimum_required(VERSION 3.12)

project(CppPlayground)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# generates 'compile_commands.json' file
set(CMAKE_EXPORT_COMPILE_COMMANDS True)

file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "src/*.cxx")
add_executable(playgroud ${SOURCES})

# add_executable(playground 
#   ${SOURCE_DIR}/*.cxx
  # ${SOURCE_DIR}/env_check.cxx
  # ${SOURCE_DIR}/util.cxx
  # ${SOURCE_DIR}/cpp17-stl-update.cxx
  # ${SOURCE_DIR}/forward-ref.cxx
  # ${SOURCE_DIR}/meta-programming.cxx
# )


