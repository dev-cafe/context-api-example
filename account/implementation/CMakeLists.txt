add_library(
    c_account
    SHARED
    c_cpp_interface.cpp
    cpp_implementation.cpp
    )

target_include_directories(
    c_account
    PRIVATE
    ${PROJECT_BINARY_DIR}
    ${PROJECT_SOURCE_DIR}/account
    )

add_library(fortran_account SHARED fortran_implementation.f90)
