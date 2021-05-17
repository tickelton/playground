set(BINARY ${CMAKE_PROJECT_NAME})

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)
list(FILTER SOURCES EXCLUDE REGEX ".*boopr\..*$")

include(CMakePrintHelpers)
cmake_print_variables(SOURCES)

set(SOURCES ${SOURCES})
set(BOOPR_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/boopr.cpp")

add_compile_options(-Wall -Wextra -pedantic -Werror)

add_executable(${BINARY}_run ${SOURCES})
add_executable(boopr ${BOOPR_SOURCES})

if(BUILD_TESTING)
    add_library(${BINARY}_lib STATIC ${SOURCES})
endif()
