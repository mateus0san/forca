#include <stdlib.h>
#include <string.h>
#include "lib/forca.h"
#include "lib/palavras.h"
#include "lib/forca_arquivo.h"

static char *escolher_palavra_lista(const char *const *); // dado uma lista de palavras, escolhe uma aleatoriamente
static struct ForcaGame new_ForcaGame(struct PalavraLista); // retorna nova instancia da struct ForcaGame
     
struct ForcaGame forca_dados_novo_jogo(int argc, const char *const argv[]) {
  struct PalavraLista lista_palavras = forca_arquivo_retorne_lista_palavra(argc, argv);
  
  return new_ForcaGame(lista_palavras);
}

void free_ForcaGame(struct ForcaGame game_dados) {
  free(game_dados.palavra);
  free(game_dados.dica);  
}

  /* inicializando a struct
     um comportamento semelhante a inicialização
     de objetos(Programação orientada a objetos)
     em uma função definada em um escopo privado (static).
   */
static struct ForcaGame new_ForcaGame(struct PalavraLista lista_palavras) {
   struct ForcaGame game_dados;

   game_dados.palavra = escolher_palavra_lista(lista_palavras.lista_palavras);
   game_dados.dica = lista_palavras.nome_lista;

  return game_dados;
}

static char *escolher_palavra_lista(const char *const lista_palavras[]) {
  int count = 0; // quantas palavras há na lista

  /* a definição de lista de palavras aqui foi definida no
     palavras.h/programacao.c, onde no final da lista a um NULL */
  while (lista_palavras[count] != NULL) {
    count++;
  }
  unsigned index = rand() % count;

  char *palavra = malloc(strlen(lista_palavras[index]) + 1);
  strcpy(palavra, lista_palavras[index]);

  return palavra;
}
