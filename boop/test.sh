#!/bin/sh

BUILDDIR='build'

[ ! -d "$BUILDDIR" ] && echo "build directory not found" && exit 1

cd "$BUILDDIR"
ctest
cd ..

