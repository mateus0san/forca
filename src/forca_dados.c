#include <stdlib.h>
#include <string.h>
#include "lib/forca.h"
#include "lib/palavras.h"
#include "lib/forca_arquivo.h"

static char *escolher_palavra_lista(const char *const *); // dado uma lista de palavras, escolhe uma aleatoriamente
static struct ForcaGame new_ForcaGame(struct PalavraLista); // nova instancia da struct ForcaGame
static char *new_adivinha_palavra(char *); // trata a palavra secreta

     
struct ForcaGame forca_dados_novo_jogo(int argc, const char *const argv[]) {
  struct PalavraLista lista_palavras = forca_arquivo_retorne_lista_palavra(argc, argv);
  
  struct ForcaGame lista = new_ForcaGame(lista_palavras);

  return lista;
}

void free_ForcaGame(struct ForcaGame game_dados) {
  free(game_dados.palavra_dados.palavra);
  free(game_dados.palavra_dados.dica);  
}

  /* inicializando a struct
     um comportamento semelhante a inicialização
     de objetos(Programação orientada a objetos)
     em uma função definada em um escopo privado (static).
   */
static struct ForcaGame new_ForcaGame(struct PalavraLista lista_palavras) {
   struct ForcaGame game_dados;

   game_dados.palavra_dados.palavra = escolher_palavra_lista(lista_palavras.lista_palavras);
   game_dados.palavra_dados.ad_palavra = new_adivinha_palavra(game_dados.palavra_dados.palavra); 
   game_dados.palavra_dados.dica = lista_palavras.nome_lista;
   game_dados.numero_acertos = game_dados.numero_erros = 0;

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


static char *new_adivinha_palavra(char *palavra) {
  int len_palavra = strlen(palavra);
  char *esconder_palavra = malloc(len_palavra + 1);

  for (int i = 0; i < len_palavra; i++) {
    esconder_palavra[i] = (palavra[i] == ' ') ? ' ' : '_';
  }

  esconder_palavra[len_palavra] = '\0';

  return esconder_palavra;
}

