cmake_minimum_required(VERSION 3.10)

project(JogoDaForca C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

include_directories(src src/palavras)

set(SOURCES
    src/main.c
    src/forca_arquivo.c
    src/forca_desenha.c
    src/forca_dados.c
    src/palavras/palavras_arquivos/programacao.c
    src/palavras/palavras_arquivos/animais.c
    src/palavras/palavras_arquivos/tecnologia.c
    src/palavras/palavras.c
)

add_executable(forca ${SOURCES})
