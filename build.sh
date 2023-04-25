#!/usr/bin/env bash

# x86 usará o nível de optimização 2, pois o 3 só foi habilitado universalmente recentemente 
compiler_linux64="clang -target x86_64-v2-pc-linux-gnu -fuse-ld=lld "
compiler_linux32="clang -target i386-pc-linux-gnu -fuse-ld=lld "
compiler_windows64="clang -target x86_64-v2-pc-win32 -fuse-ld=lld "
compiler_windows32="clang -target i386-pc-win32 -fuse-ld=lld "

input="src/main.c src/tree.c src/reader.c"

fedora_flags=(
    "-O2"
    "-flto=auto"
    "-ffat-lto-objects"
    "-fexceptions"
    "-g"
    "-grecord-gcc-switches"
    "-pipe"
    "-Wall"
    "-Werror=format-security"
    "-Wp,-D_FORTIFY_SOURCE=2"
    "-Wp,-D_GLIBCXX_ASSERTIONS"
    "-specs=/usr/lib/rpm/redhat/redhat-hardened-cc1"
    "-fstack-protector-strong"
    "-specs=/usr/lib/rpm/redhat/redhat-annobin-cc1"
    "-m64"
    "-mtune=generic"
    "-fasynchronous-unwind-tables"
    "-fstack-clash-protection"
    "-fcf-protection"
)

flags=(
    "-Wall"
    "-Wextra"
    "--analyze"
    "-Xanalyzer" # Clang flag
    "-analyzer-output=text" # Clang flag
    # "-fanalyzer"  # GCC flag
    "-std=gnu17"
    "-pedantic"
    "-O2"
    "-D_FORTIFY_SOURCE=3"
    "-fwrapv"
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

$compiler_linux64 "${flags[@]}" -o build/calculadora_linux64 $input
# "$compiler_linux32" "${flags[@]}" -o build/calculadora_linux32 "$input"

# Preciso conseguir as bibliotecas do Windows para fazer essa compilação
# "$compiler_windows64" "${flags[@]}" -o build/calculadora_win64 "$input"
# "$compiler_windows32" "${flags[@]}" -o build/calculadora_win32 "$input"
