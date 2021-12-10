cmake_minimum_required(VERSION 3.13)

project(drived)

add_library(drived SHARED drived.cpp)

target_include_directories(drived PRIVATE ${CMAKE_SOURCE_DIR}/include)

set_target_properties(drived PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

target_link_libraries(drived PRIVATE base)

install(TARGETS drived LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)