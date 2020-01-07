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
    ${PROJECT_BINARY_DIR}/account
    )

add_library(
    account_fortran_implementation
    SHARED
    fortran_implementation.f90
    )

install(
    TARGETS
        account_cpp_implementation
        account_fortran_implementation
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    )
