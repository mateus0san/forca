cmake_minimum_required(VERSION 3.10)

project(JogoDaForca C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

include_directories(src/)

add_compile_options(-Wall -Wextra -pedantic)

set(SOURCES
    src/main.c
    src/forca_data.c
    src/forca_draw.c
    src/forca_draw.h
    src/forca_game.c
    src/forca.h
    src/forca_system.c
    src/forca_system.h
)

add_executable(forca ${SOURCES})
