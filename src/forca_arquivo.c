/* forca_aquivo.c deve lidar com arquivos relacionados ao
   jogo e em caso de erro, chamar fallback para usar uma
   lista de palavras padrão, definida em palavras/palavras.h
*/ 
#include "palavras/palavras.h"
#include "forca.h"

const char **forca_arquivo_carregar_fallback() {
  return palavras_retorne_lista_padrao();
}
