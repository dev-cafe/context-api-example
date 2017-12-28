# specify where to place libraries
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# implementation sources
add_subdirectory(implementation)

# fortran interface
add_library(fortran_c_interface account.f90)

INSTALL(
    FILES
        account.h
        account.f90
    DESTINATION
        include
    )
