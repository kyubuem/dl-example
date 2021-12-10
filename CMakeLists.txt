cmake_minimum_required(VERSION 3.13)

project(DLExample)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CXX_STANDARD 17 CACHE STRING "The C++ standard to use")
set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/install)

add_subdirectory(base)
add_subdirectory(derived)
add_subdirectory(example)

install(DIRECTORY include DESTINATION ${CMAKE_INSTALL_PREFIX})
