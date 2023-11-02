cmake_minimum_required(VERSION 3.28)
project(module_example CXX)

set(CMAKE_CXX_STANDARD 20)

# Create a library
add_library(example)
# Add the module file to the library
target_sources(example
  PUBLIC
    FILE_SET CXX_MODULES FILES
      Example.cppm
)
# Create an executable
add_executable(hello main.cpp)
# Link to the library foo
target_link_libraries(hello example)
