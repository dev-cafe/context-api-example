add_library(
    c_account
    SHARED
    c_cpp_interface.cpp
    cpp_implementation.cpp
    )

target_include_directories(
    c_account
    PRIVATE
    ${PROJECT_SOURCE_DIR}/account
    ${PROJECT_BINARY_DIR}/account/implementation
    )

add_library(fortran_account SHARED fortran_implementation.f90)

# generate account_export.h
include(GenerateExportHeader)
generate_export_header(
    c_account
    BASE_NAME account
    )
