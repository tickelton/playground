cmake_minimum_required(VERSION 3.10)

project(boop)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

enable_testing()

add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(lib/googletest)
