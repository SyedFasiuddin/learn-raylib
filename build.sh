#/bin/sh

set -xe
mkdir -p build

clang $(pkg-config --libs --cflags raylib) -o build/main main.c
