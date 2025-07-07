cmake_minimum_required(VERSION 3.10)

project(JogoDaForca C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

include_directories(src src/palavras)

set(SOURCES
    src/main.c
    src/forca_arquivo.c
    src/palavras/programacao.c
)

add_executable(forca ${SOURCES})
