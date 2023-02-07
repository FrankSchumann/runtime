cmake_minimum_required( VERSION 3.15 )

project( PackageTest CXX )

find_package( runtime CONFIG REQUIRED )
find_package( copa CONFIG REQUIRED )

add_executable( example src/example.cpp src/FactoryController.cpp src/ComponentController.cpp )
target_link_libraries(example runtime::runtime copa::copa)
