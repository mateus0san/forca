cmake_minimum_required(VERSION 3.10)

project(JogoDaForca C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

include_directories(src/)

add_compile_options(-Wall -Wextra -pedantic)

set(SOURCES
    src/main.c
    src/forca_arquivo.c
    src/forca_desenha.c
    src/forca_dados.c
    src/forca_jogar.c
    src/forca_programacao.c
    src/forca_animais.c
    src/forca_tecnologia.c
    src/forca_palavras.c
    src/forca_string.c
    src/windows_linux.c
)

add_executable(forca ${SOURCES})
