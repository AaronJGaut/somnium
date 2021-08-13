cmake_minimum_required(VERSION 3.10)

project(remwave)

find_library(vulkan vulkan)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(VULKAN_DIR /home/gaut/code/vulkan-sdk/1.2.182.0/x86_64)

add_library(remwave STATIC src/core.cpp)
target_include_directories(remwave PUBLIC ./include)
target_compile_options(remwave PUBLIC -Wall -Wextra -Werror)

# tests

add_executable(test_check test/code/test_check.cpp)
target_link_libraries(test_check remwave vulkan)
