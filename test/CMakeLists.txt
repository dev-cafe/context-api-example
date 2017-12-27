add_executable(c_testing_c test.cpp)
target_include_directories(
    c_testing_c
    PUBLIC
    ${PROJECT_BINARY_DIR}
    ${PROJECT_SOURCE_DIR}/account
    )
target_link_libraries(c_testing_c c_account)
add_test(c_testing_c ${PROJECT_BINARY_DIR}/test/c_testing_c)

add_executable(c_testing_f test.cpp)
target_include_directories(
    c_testing_f
    PUBLIC
    ${PROJECT_BINARY_DIR}
    ${PROJECT_SOURCE_DIR}/account
    )
target_link_libraries(c_testing_f fortran_account)
add_test(c_testing_f ${PROJECT_BINARY_DIR}/test/c_testing_f)

add_executable(f_testing_c test.f90)
target_include_directories(
    f_testing_c
    PUBLIC
    ${PROJECT_BINARY_DIR}/account
    )
target_link_libraries(f_testing_c c_account fortran_c_interface)
add_test(f_testing_c ${PROJECT_BINARY_DIR}/test/f_testing_c)

add_executable(f_testing_f test.f90)
target_include_directories(
    f_testing_f
    PUBLIC
    ${PROJECT_BINARY_DIR}/account
    )
target_link_libraries(f_testing_f fortran_account fortran_c_interface)
add_test(f_testing_f ${PROJECT_BINARY_DIR}/test/f_testing_f)
