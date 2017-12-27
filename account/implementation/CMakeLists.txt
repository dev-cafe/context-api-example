add_library(
    account_cpp_implementation
    SHARED
    c_cpp_interface.cpp
    cpp_implementation.cpp
    )

target_include_directories(
    account_cpp_implementation
    PRIVATE
    ${PROJECT_SOURCE_DIR}/account
    ${PROJECT_BINARY_DIR}/account/implementation
    )

add_library(
    account_fortran_implementation
    SHARED
    fortran_implementation.f90
    )

# generate account_export.h
include(GenerateExportHeader)
generate_export_header(
    account_cpp_implementation
    BASE_NAME account
    )

INSTALL(
    FILES
        ${PROJECT_BINARY_DIR}/account/implementation/account_export.h
    DESTINATION
        include
    )

install(
    TARGETS
        account_cpp_implementation
        account_fortran_implementation
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    )
