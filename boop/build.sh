#!/bin/bash

BUILDDIR='build'
CMAKE_BUILD_TYPE="Debug"
CMAKE_BUILD_TESTING="Off"

print_usage() {
    echo "$0 [-h|--help] [-v|--verbose] [--clang] [--clean] [--release] [--test]"
    echo "    -h|--help:    show this help message"
    echo "    -v|--verbose: enable verbose output for 'make'"
    echo "    --clang:      use Clang instead of the system default compiler"
    echo "    --clean:      delete build directory before starting new build"
    echo "    --release:    set CMAKE_BUILD_TYPE to Release"
    echo "    --test:       build and run tests"
}

for arg in "$@"; do
    case $arg in
        --clang)
            export CC=clang
            export CXX=clang++
        ;;
        -h|--help)
            print_usage
            exit 0
        ;;
        --clean)
            rm -rf $BUILDDIR
        ;;
        --release)
            CMAKE_BUILD_TYPE="Release"
        ;;
        --test)
            CMAKE_BUILD_TESTING="On"
        ;;
        -v|--verbose)
            MAKE_VERBOSE="VERBOSE=1"
        ;;
    esac
done


[ -d "$BUILDDIR" ] || mkdir "$BUILDDIR"

cd "$BUILDDIR"

cmake -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE} -DBUILD_TESTING=${CMAKE_BUILD_TESTING} .. && make ${MAKE_VERBOSE}
[ "$CMAKE_BUILD_TESTING" = "On" ] && ctest .

cd ..
