cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(example CXX Fortran)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(${PROJECT_SOURCE_DIR}/api)
include_directories(${PROJECT_BINARY_DIR})

add_library(c_example SHARED src/bank.cpp)
add_library(f_example SHARED src/bank.f90)

add_executable(c_testing_c test/test.cpp)
target_link_libraries(c_testing_c c_example)

add_executable(c_testing_f test/test.cpp)
target_link_libraries(c_testing_f f_example)

add_executable(f_testing_c test/test.f90)
target_link_libraries(f_testing_c c_example)

add_executable(f_testing_f test/test.f90)
target_link_libraries(f_testing_f f_example)

include(GenerateExportHeader)
generate_export_header(c_example)
