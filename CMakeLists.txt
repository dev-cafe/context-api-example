cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(example)

enable_language(CXX)
enable_language(Fortran)

include_directories(${PROJECT_SOURCE_DIR}/api)

add_library(c_example SHARED src/bank.cpp)
add_library(f_example SHARED src/bank.f90)
