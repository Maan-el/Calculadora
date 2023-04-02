#!/usr/bin/env bash

compiler_linux64="gcc"
compiler_windows64="x86_64-w64-mingw32-gcc"
compiler_windows32="i686-w64-mingw32-gcc"

input="src/main.c"

# V3 só foi habilitada "universalmente" recentemente, então vou usar só o V2
x86_optimization="-march=x86-64-v2"

flags=(
    "-Wall"
    "-Wextra"
    "-fanalyzer"
    "-std=c2x"
    "-pedantic"
    "-O1"
    "-D_FORTIFY_SOURCE=3"
    "-Wl,-z,relro,-z,now"
    "-ggdb3"
    "-Wshadow"
    "-Wpointer-arith"
    "-Wwrite-strings"
    "-Wconversion"
    "-fsanitize=address"
    "-fsanitize=undefined"
    "-Wuninitialized"
    "-Wunreachable-code"
    "-Wundef"
    "-Wcast-qual"
    "-Wcast-align"
    "-Wswitch-enum"
    "-Wfloat-equal"
    "-Wstrict-prototypes"
    "-Wpadded"
    "-Wno-unused-function"
    "-Wno-unused-parameter"
)

"$compiler_linux64" "$x86_optimization" "${flags[@]}" -o build/calculadora_linux64 "$input"
"$compiler_windows64" "$x86_optimization" "${flags[@]}" -o build/calculadora_win64 "$input"
"$compiler_windows32" "${flags[@]}" -o build/calculadora_win32 "$input"
