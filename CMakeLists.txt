cmake_minimum_required (VERSION 3.0)
if (COMMAND cmake_policy)
  cmake_policy (SET CMP0003 NEW)
endif (COMMAND cmake_policy)

project (GFTL
  VERSION 1.2.7
  LANGUAGES Fortran)

if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set (CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/installed" CACHE PATH "..." FORCE)
  message("-- Setting default install prefix to ${CMAKE_INSTALL_PREFIX}.")
  message("   Override with -DCMAKE_INSTALL_PREFIX=<path>.")
endif ()

# For BSD systems use GNU m4
find_program( M4 NAMES "gm4" "m4")
if( NOT M4 )
  message( SEND_ERROR "m4 program not found" )
endif()

add_subdirectory (include)
add_subdirectory (examples)

find_package (PFUNIT 4.1 QUIET)
if (PFUNIT_FOUND)
  message("-- Detecting pFUnit: ${PFUNIT_DIR}")
  project (GFTL-TEST
    VERSION ${GFTL_VERSION}
    LANGUAGES Fortran
    )

  set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${GFTL_SOURCE_DIR}/cmake_utils")
  include (${CMAKE_Fortran_COMPILER_ID} RESULT_VARIABLE found)
  include (CheckFortranSource)
  include (CheckCompilerCapabilities)

  enable_testing()
  if (NOT TARGET tests)
    add_custom_target(tests COMMAND ${CMAKE_CTEST_COMMAND})
  endif ()
  
  add_subdirectory(tests EXCLUDE_FROM_ALL)
endif ()

configure_file(GFTLConfig.cmake.in ${CMAKE_CURRENT_BINARY_DIR}/GFTLConfig.cmake @ONLY)
configure_file(GFTLConfig-version.cmake.in ${CMAKE_CURRENT_BINARY_DIR}/GFTLConfig-version.cmake @ONLY)

set (top_dir "GFTL-${GFTL_VERSION_MAJOR}.${GFTL_VERSION_MINOR}")
install (
  FILES ${CMAKE_CURRENT_BINARY_DIR}/GFTLConfig.cmake ${CMAKE_CURRENT_BINARY_DIR}/GFTLConfig-version.cmake
  DESTINATION "${top_dir}/cmake"
  )

# The following is needed for external projects using *nix make when
# parent project builds gFTL as a subproject.
set (GFTL_TOP_DIR "${CMAKE_INSTALL_PREFIX}/${top_dir}" CACHE PATH "")
configure_file(GFTL.mk.in ${CMAKE_CURRENT_BINARY_DIR}/GFTL.mk @ONLY)
install (
  FILES ${CMAKE_CURRENT_BINARY_DIR}/GFTL.mk 
  DESTINATION "${top_dir}/include"
  )
