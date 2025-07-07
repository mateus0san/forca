#include "palavras.h"
#include <stdlib.h>

const char **palavras_retorne_lista_padrao() {
  // gera um número aleatório entre 0 e PALAVRA_LISTA_NUMERO - 1
  unsigned i = rand() % PALAVRA_LISTA_NUMERO;  


  /* após ler os comentários de palavras.h
     adicione aqui a nova lista de palavras
     lembre de atualizar o cmake após adicionar */
  switch (i) {
    case 0:
      return palavras_programacao;
    case 1:
      return palavras_animais;
    default:
      return palavras_programacao;
  }
}
