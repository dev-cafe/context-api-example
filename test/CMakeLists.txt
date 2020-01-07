add_executable(c_testing_c test.cpp)
target_include_directories(
    c_testing_c
    PRIVATE
    ${PROJECT_SOURCE_DIR}/account
    ${PROJECT_BINARY_DIR}/account
    )
target_link_libraries(c_testing_c account_cpp_implementation)

add_executable(c_testing_fortran test.cpp)
target_include_directories(
    c_testing_fortran
    PRIVATE
    ${PROJECT_SOURCE_DIR}/account
    ${PROJECT_BINARY_DIR}/account
    )
target_link_libraries(c_testing_fortran account_fortran_implementation)

add_executable(fortran_testing_c test.f90)
target_include_directories(
    fortran_testing_c
    PRIVATE
    ${PROJECT_BINARY_DIR}/account
    )
target_link_libraries(fortran_testing_c account_cpp_implementation fortran_c_interface)

add_executable(fortran_testing_fortran test.f90)
target_include_directories(
    fortran_testing_fortran
    PRIVATE
    ${PROJECT_BINARY_DIR}/account
    )
target_link_libraries(fortran_testing_fortran account_fortran_implementation fortran_c_interface)

foreach(_test c_testing_c c_testing_fortran fortran_testing_c fortran_testing_fortran)
    add_test(${_test} ${PROJECT_BINARY_DIR}/test/${_test})
endforeach()

file(
  CREATE_LINK
    ${CMAKE_CURRENT_SOURCE_DIR}/test_account.py
    ${PROJECT_BINARY_DIR}/${PYMOD_INSTALL_FULLDIR}/../test_account.py
  SYMBOLIC
  )

# FIXME Does not work
#add_test(
#  NAME
#    cffi-test
#  COMMAND
#    ${Python_EXECUTABLE} -m pytest -rws -vv ${PROJECT_BINARY_DIR}/${PYMOD_INSTALL_FULLDIR}/../test_account.py
#  WORKING_DIRECTORY
#    ${CMAKE_CURRENT_BINARY_DIR}
#  )

install(
  FILES
    test_account.py
  DESTINATION
    ${PYMOD_INSTALL_FULLDIR}/..
  )
