cmake_minimum_required( VERSION 3.15 )

project( PackageTest CXX )

find_package( core CONFIG REQUIRED )
find_package( runtime CONFIG REQUIRED )

add_executable( example src/example.cpp src/FactoryController.cpp src/ComponentController.cpp )

include_directories( ${core_INCLUDE_DIR} )

target_link_libraries(example runtime::runtime core::core)
