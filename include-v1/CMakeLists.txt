set (dest "GFTL-${GFTL_VERSION}")

add_library (gftl-v1 INTERFACE)
target_include_directories (gftl-v1 INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}> # for headers when building
  $<INSTALL_INTERFACE:${dest}/include-v1>           # for client in install mode
  )

find_program( M4 m4)
if( NOT M4 )
  message( SEND_ERROR "m4 program not found" )
endif()

add_subdirectory (templates)
add_subdirectory (types)

add_custom_target (force-generation-of-includes ALL)
add_dependencies (force-generation-of-includes gftl-v1)

install (TARGETS gftl-v1 EXPORT GFTL DESTINATION "${dest}/include-v1")
install (EXPORT GFTL NAMESPACE gFTL:: DESTINATION "${dest}/lib/cmake/GFTL")


