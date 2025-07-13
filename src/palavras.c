#include "palavras.h"
#include <stdlib.h>

struct PalavraLista palavras_retorne_lista_padrao() {
  // unsigned, é numero sem sinal, apenas número positivo
  // rand gera um número aleatorio entre 0 e NUMERO_DE_FUNCOES - 1
  unsigned i = rand() % NUMERO_DE_FUNCOES;


  /* após ler os comentários de palavras.h
     adicione aqui a nova lista de palavras
     novo case + 1
     e copie os passos das funções anteriores
  */

  switch (i) {
    case 1:
      return palavras_animais_funcao();
    case 2:
      return palavras_tecnologia_funcao();
    default:
      return palavras_programacao_funcao();
  }
}

void free_lista_palavras(struct PalavraLista *lista) {
  for (int i = 0; lista->lista_palavras[i] != NULL; i++)
    free((void *)lista->lista_palavras[i]);
  free((void *) lista->lista_palavras);
}
