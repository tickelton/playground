cmake_minimum_required(VERSION 3.10)

project(boop)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_subdirectory(src)
if(BUILD_TESTING)
    enable_testing()
    add_subdirectory(tests)
    add_subdirectory(lib/googletest)
endif()
