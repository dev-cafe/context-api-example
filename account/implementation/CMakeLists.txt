# c++ implementation
add_library(c_account SHARED account.cpp)

target_include_directories(
    c_account
    PRIVATE
    ${PROJECT_BINARY_DIR}
    ${PROJECT_SOURCE_DIR}/account
    )

# fortran implementation
add_library(f_account SHARED account.f90)
