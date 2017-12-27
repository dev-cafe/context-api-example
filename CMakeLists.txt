# define minimum cmake version
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

# project name and supported languages
project(example CXX Fortran)

# require C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# specify where to place libraries
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# interface and sources
add_subdirectory(account)

# tests
enable_testing()
add_subdirectory(test)

# generate c_account_export.h
include(GenerateExportHeader)
generate_export_header(c_account)
