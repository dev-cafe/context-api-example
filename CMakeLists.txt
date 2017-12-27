cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(example CXX Fortran)

# require C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR}/account)
include_directories(${PROJECT_BINARY_DIR})

add_library(c_account SHARED account/implementation/account.cpp)
add_library(f_account SHARED account/implementation/account.f90)

enable_testing()

add_executable(c_testing_c test/test.cpp)
target_link_libraries(c_testing_c c_account)
add_test(c_testing_c ${PROJECT_BINARY_DIR}/c_testing_c)

add_executable(c_testing_f test/test.cpp)
target_link_libraries(c_testing_f f_account)
add_test(c_testing_f ${PROJECT_BINARY_DIR}/c_testing_f)

add_executable(f_testing_c test/test.f90)
target_link_libraries(f_testing_c c_account)
add_test(f_testing_c ${PROJECT_BINARY_DIR}/f_testing_c)

add_executable(f_testing_f test/test.f90)
target_link_libraries(f_testing_f f_account)
add_test(f_testing_f ${PROJECT_BINARY_DIR}/f_testing_f)

include(GenerateExportHeader)
generate_export_header(c_account)
