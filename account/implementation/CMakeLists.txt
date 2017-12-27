add_library(
    c_account
    SHARED
    cpp_implementation.cpp
    c_cpp_interface.cpp
    )

target_include_directories(
    c_account
    PRIVATE
    ${PROJECT_BINARY_DIR}
    ${PROJECT_SOURCE_DIR}/account
    )

add_library(f_account SHARED fortran_implementation.f90)
