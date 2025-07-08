#include "palavras.h"
#include <stdlib.h>
#include <string.h>

const char *const *palavras_retorne_lista_padrao(char *nome_lista) {
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
      nome_lista = strdup("animais");
      return palavras_animais_funcao();
    default:
      nome_lista = strdup("programacao");
      return palavras_programacao_funcao();
  }
}
