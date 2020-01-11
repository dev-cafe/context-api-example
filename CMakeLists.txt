# define minimum cmake version
cmake_minimum_required(VERSION 3.14)

# project name and supported languages
project(example LANGUAGES CXX Fortran C)

include(GNUInstallDirs)

# require C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# require C99
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_C_STANDARD_REQUIRED ON)

# specify where to place libraries
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Python is required to get the Python interface working
find_package(Python 3.7 REQUIRED COMPONENTS Development Interpreter)
file(TO_NATIVE_PATH "lib/python${Python_VERSION_MAJOR}.${Python_VERSION_MINOR}/account" PYMOD_INSTALL_FULLDIR)

# interface and sources
add_subdirectory(account)

# tests
enable_testing()
add_subdirectory(test)
