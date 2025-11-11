cmake_minimum_required(VERSION 3.16)

project(RedBlackTree VERSION 1.0 LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

add_executable(bst main.cpp bst.cpp)
