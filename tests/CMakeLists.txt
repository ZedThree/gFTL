
add_subdirectory (shared)
add_subdirectory (Vector)
add_subdirectory (Map)
add_subdirectory (Set)
add_subdirectory (altSet)

# Need to expand intrinsic template for various types with m4
add_subdirectory(include) 


include_directories (${PFUNIT}/include)
link_directories (${PFUNIT}/lib)

include_directories (${CMAKE_CURRENT_SOURCE_DIR})
include_directories (${GFTL_SOURCE_DIR}/tests/shared)
include_directories (${GFTL_BINARY_DIR}/tests/shared)

include_directories (${CMAKE_CURRENT_BINARY_DIR}/Set)
include_directories (${CMAKE_CURRENT_BINARY_DIR}/altSet)
include_directories (${CMAKE_CURRENT_BINARY_DIR}/Map)
include_directories (${CMAKE_CURRENT_BINARY_DIR}/Vector)

include_directories (${CMAKE_CURRENT_BINARY_DIR}/altSet/SUT)
include_directories (${CMAKE_CURRENT_BINARY_DIR}/Set/SUT)
include_directories (${CMAKE_CURRENT_BINARY_DIR}/Map/SUT)
include_directories (${CMAKE_CURRENT_BINARY_DIR}/Vector/SUT)

include_directories (${CMAKE_CURRENT_SOURCE_DIR}/altSet)
include_directories (${CMAKE_CURRENT_SOURCE_DIR}/Set)
include_directories (${CMAKE_CURRENT_SOURCE_DIR}/Map)
include_directories (${CMAKE_CURRENT_SOURCE_DIR}/Vector)

#set(driver ${PFUNIT_TOP_DIR}/include/driver.F90)
#add_executable(tests.x EXCLUDE_FROM_ALL ${driver})
#target_link_libraries(tests.x testVector vectorSUT testaltSet altsetSUT testSet setSUT testMap mapSUT shared pfunit)


