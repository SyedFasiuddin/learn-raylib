#/bin/sh

set -xe
mkdir -p build

cc $(pkg-config --libs --cflags raylib) -o build/main main.c
# x86_64-w64-mingw32-gcc -L./raylib/lib -I./raylib/include -o build/win main.c \
#     -lraylib -lopengl32 -lwinmm -lgdi32 -static
