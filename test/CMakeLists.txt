cmake_minimum_required( VERSION 3.15 )

project( runtimeTest 
        VERSION 0.0.0.0  
        DESCRIPTION "runtime Plugin Test" )

set( CMAKE_CXX_STANDARD 17 )

include( FetchContent )
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set( gtest_force_shared_crt ON CACHE BOOL "" FORCE )
FetchContent_MakeAvailable( googletest )

enable_testing()

file( GLOB_RECURSE PROJECT_SOURCE_FILES src/*.cpp ../src/*.cpp )

find_package( core CONFIG REQUIRED ) 
find_package( osal CONFIG REQUIRED )

add_executable( ${CMAKE_PROJECT_NAME} ${PROJECT_SOURCE_FILES} )

include_directories( ${PROJECT_BINARY_DIR} ../include ../src ${core_INCLUDE_DIR} ${osal_INCLUDE_DIR} )

# Create a simple configuration header
configure_file( ../config.h.in config.h )

target_link_libraries(
  ${CMAKE_PROJECT_NAME}
  core::core
  osal::osal
  GTest::gmock_main
  GTest::gtest_main
)

include( GoogleTest )
gtest_discover_tests( ${CMAKE_PROJECT_NAME} )
