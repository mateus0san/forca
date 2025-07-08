#include "palavras.h"
#include <stdlib.h>

const char *const *palavras_retorne_lista_padrao() {
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
      // strdup retorna um ponteiro para a nova string alocada com malloc
      // precisa usar free depois
      // caso não consiga alocar ela retorna NULL
      return palavras_animais_funcao();
    default:
      return palavras_programacao_funcao();
  }
}
