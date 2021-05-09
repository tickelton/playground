#!/bin/sh

BUILDDIR='build'
[ -d "$BUILDDIR" ] || mkdir "$BUILDDIR"

cd "$BUILDDIR"

cmake .. && make

