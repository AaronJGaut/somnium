cmake_minimum_required(VERSION 3.10)

project(somnium)

find_library(vulkan vulkan)
find_package(pybind11 REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(somnium STATIC
    src/Context.cpp
    src/Target.cpp
    src/Scene.cpp
    src/Camera.cpp
    src/Renderer.cpp
)
target_include_directories(somnium PUBLIC ./include)
target_compile_options(somnium PUBLIC -Wall -Wextra -Werror -Wno-unused-parameter -fPIC)

# python binding

pybind11_add_module(pysomnium MODULE src/python.cpp)
target_include_directories(pysomnium PRIVATE ./include)
target_link_libraries(pysomnium PRIVATE somnium vulkan)
set_target_properties(pysomnium PROPERTIES OUTPUT_NAME somnium)

# tests

add_executable(test_check test/code/test_check.cpp)
target_link_libraries(test_check somnium vulkan)
