# Get file extension for Python module
execute_process(
  COMMAND
    "${Python_EXECUTABLE}" "-c" "from distutils import sysconfig as s;print(s.get_config_var('EXT_SUFFIX'))"
  RESULT_VARIABLE _PYTHON_SUCCESS
  OUTPUT_VARIABLE Python_MODULE_EXTENSION
  ERROR_VARIABLE _PYTHON_ERROR_VALUE
  OUTPUT_STRIP_TRAILING_WHITESPACE
  )

# Call CFFI to generate bindings source file _account.cc
file(MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/generated)
add_custom_command(
  OUTPUT
    ${PROJECT_BINARY_DIR}/generated/_account.c
  COMMAND
    ${Python_EXECUTABLE} ${CMAKE_CURRENT_LIST_DIR}/builder.py
  MAIN_DEPENDENCY
    ${CMAKE_CURRENT_LIST_DIR}/builder.py
  DEPENDS
    ${CMAKE_CURRENT_LIST_DIR}/account.f90
    ${CMAKE_CURRENT_LIST_DIR}/account.h
  WORKING_DIRECTORY
    ${PROJECT_BINARY_DIR}/generated
  )

add_custom_target(
  cffi-builder
  ALL
  DEPENDS
    ${PROJECT_BINARY_DIR}/generated/_account.c
  )

Python_add_library(_account
  MODULE
    account.f90
    ${PROJECT_BINARY_DIR}/generated/_account.c
  )

add_dependencies(_account cffi-builder)

# generate account_export.h
include(GenerateExportHeader)
generate_export_header(_account
  BASE_NAME account
  )

target_include_directories(_account
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}  # where account.h lives
    ${CMAKE_CURRENT_BINARY_DIR}  # where lsdalton_py_export.h lives
  )

# implementation sources
add_subdirectory(implementation)

target_link_libraries(_account
  PUBLIC
    account_fortran_implementation
  )

# fortran interface
add_library(fortran_c_interface account.f90)

# RPATH fixing
file(RELATIVE_PATH _rel ${CMAKE_INSTALL_PREFIX}/${PYMOD_INSTALL_FULLDIR} ${CMAKE_INSTALL_PREFIX})
if(APPLE)
  set(_RPATH "@loader_path/${_rel}")
else()
  set(_RPATH "\$ORIGIN/${_rel}")
endif()

# List of Python files around the compiled extension
list(APPEND _pys
  ${CMAKE_CURRENT_SOURCE_DIR}/__init__.py
  ${CMAKE_CURRENT_SOURCE_DIR}/shim.py
  )

set_target_properties(_account
  PROPERTIES
    SUFFIX "${Python_MODULE_EXTENSION}"
    MACOSX_RPATH ON
    SKIP_BUILD_RPATH OFF
    BUILD_WITH_INSTALL_RPATH OFF
    INSTALL_RPATH "${_RPATH}${CMAKE_INSTALL_LIBDIR}"
    INSTALL_RPATH_USE_LINK_PATH ON
    LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/${PYMOD_INSTALL_FULLDIR}
    RESOURCE "${_pys}"
  )

# Create symlinks into build tree
file(MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/${PYMOD_INSTALL_FULLDIR})
foreach(_py IN LISTS _pys)
  get_filename_component(__py ${_py} NAME)
  file(
    CREATE_LINK
      ${_py}
      ${PROJECT_BINARY_DIR}/${PYMOD_INSTALL_FULLDIR}/${__py}
    SYMBOLIC
    )
endforeach()

install(
  FILES
    account.h
    account.f90
    ${CMAKE_CURRENT_BINARY_DIR}/account_export.h
  DESTINATION
    ${CMAKE_INSTALL_INCLUDEDIR}
  )

install(
  TARGETS
    _account
  LIBRARY
    DESTINATION ${PYMOD_INSTALL_FULLDIR}/lib
  RUNTIME
    DESTINATION ${PYMOD_INSTALL_FULLDIR}/lib
  RESOURCE
    DESTINATION ${PYMOD_INSTALL_FULLDIR}
  )
