cmake_minimum_required(VERSION 3.28)
project(clang_example CXX)

set(CMAKE_CXX_STANDARD 20)

add_library(interface_part)
target_sources(interface_part
  PUBLIC
    FILE_SET CXX_MODULES FILES
      interface_part.cppm
)

add_library(impl_part)
target_sources(impl_part
  PUBLIC
    FILE_SET CXX_MODULES FILES
      impl_part.cppm
)
target_link_libraries(impl_part interface_part)

add_library(M)
target_sources(M
  PUBLIC
    FILE_SET CXX_MODULES FILES
      M.cppm
)
target_link_libraries(M interface_part impl_part)

add_library(Impl)
target_sources(Impl
  PUBLIC
    Impl.cpp
)
target_link_libraries(Impl M)

add_executable(clang-demo User.cpp)
target_link_libraries(clang-demo Impl)
