cmake_minimum_required(VERSION 3.10)

project(remwave)

find_library(vulkan vulkan)
find_package(pybind11 REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(remwave STATIC
    src/Context.cpp
    src/Target.cpp
    src/Scene.cpp
    src/Camera.cpp
    src/Renderer.cpp
)
target_include_directories(remwave PUBLIC ./include)
target_compile_options(remwave PUBLIC -Wall -Wextra -Werror -Wno-unused-parameter -fPIC)

# python binding

pybind11_add_module(pyremwave MODULE src/python.cpp)
target_include_directories(pyremwave PRIVATE ./include)
target_link_libraries(pyremwave PRIVATE remwave vulkan)
set_target_properties(pyremwave PROPERTIES OUTPUT_NAME remwave)

# tests

add_executable(test_check test/code/test_check.cpp)
target_link_libraries(test_check remwave vulkan)
