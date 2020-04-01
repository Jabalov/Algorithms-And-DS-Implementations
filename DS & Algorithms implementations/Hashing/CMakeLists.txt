cmake_minimum_required(VERSION 3.5.1)

set(CMAKE_CXX_STANDARD 14)

project(ExampleProject)

add_executable(example src/chaining.cpp src/linearprobing.cpp )
