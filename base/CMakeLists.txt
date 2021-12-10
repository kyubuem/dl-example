cmake_minimum_required(VERSION 3.13)

project(base)

add_library(base SHARED base.cpp)

target_include_directories(base PRIVATE ${CMAKE_SOURCE_DIR}/include)

set_target_properties(base PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)