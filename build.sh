#/bin/sh

set -xe

clang $(pkg-config --libs --cflags raylib) -o main main.c
