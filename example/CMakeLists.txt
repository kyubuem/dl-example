cmake_minimum_required(VERSION 3.13)

project(example)

if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
  set(CMAKE_EXE_LINKER_FLAGS "-framework Security")
endif()


add_executable(main main.cpp)

target_link_libraries(main PUBLIC base)

set_target_properties(main PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

target_include_directories(main PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_include_directories(main PRIVATE ${PROJECT_SOURCE_DIR}/include)
