# specify where to place libraries
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# implementation sources
add_subdirectory(implementation)

# fortran interface
add_library(f_interface account.f90)
