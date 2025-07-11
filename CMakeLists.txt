cmake_minimum_required(VERSION 3.10)

project(JogoDaForca C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

include_directories(src/lib)

add_compile_options(-Wall -Wextra -pedantic)

set(SOURCES
    src/main.c
    src/forca_arquivo.c
    src/forca_desenha.c
    src/forca_dados.c
    src/forca_jogar.c
    src/programacao.c
    src/animais.c
    src/tecnologia.c
    src/palavras.c
    src/forca_string.c
    src/windows_linux.c
)

add_executable(forca ${SOURCES})
