cmake_minimum_required(VERSION 3.13)

project(derived)

add_library(derived SHARED derived.cpp)

target_include_directories(derived PRIVATE ${CMAKE_SOURCE_DIR}/include)

set_target_properties(derived PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

target_link_libraries(derived PRIVATE base)
