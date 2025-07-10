/* forca_desenha é responsável por mostrar informações do jogo */

#include "forca_desenha.h"
#include <stdio.h>
#include <stdlib.h>

static void clear_screen(); 
static void forca(int);


void forca_desenha(struct ForcaDesenha desenha_dados) {
  clear_screen();
  printf("----------------------%s------------------------\n", desenha_dados.dica);
  forca(desenha_dados.erros);
  printf("erros: %d\n", desenha_dados.erros);
  printf("chutes: %s\n", desenha_dados.chutes);
  printf("Palavra: %s\n", desenha_dados.palavra_desconhecida);
}

struct ForcaDesenha forca_desenha_new_ForcaDesenha(struct ForcaGame game_dados) {
  struct ForcaDesenha desenha_dados;

  desenha_dados.palavra_desconhecida = game_dados.palavra_dados.ad_palavra;
  desenha_dados.dica = game_dados.palavra_dados.dica;
  desenha_dados.chutes[0] = '\0';
  desenha_dados.erros = game_dados.numero_erros;

  return desenha_dados;
}

struct ForcaDesenha forca_desenha_free_ForcaDesenha(struct ForcaDesenha dados) {
  // para que não aponte para ponteiros que foram desalocados com free
  dados.palavra_desconhecida = NULL;
  dados.dica = NULL;

  return dados;
}

// função que limpa a tela, compatível com linux e windows
static void clear_screen() {
  #ifdef _WIN32
      system("cls");
  #else
      system("clear");
  #endif
}

// desenha a forca
static void forca(int erros) {
  switch (erros) {
    case 0:
      printf("\
             +-------+\n\
             |       |\n\
             |\n\
             |\n\
             |\n\
             |\n");
    break;
    case 1:
      printf("\
             +-------+\n\
             |       |\n\
             |       O\n\
             |\n\
             |\n\
             |\n");
    break;
    case 2:
      printf("\
             +-------+\n\
             |       |\n\
             |       O\n\
             |       |\n\
             |\n\
             |\n");
    break;
    case 3:
      printf("\
             +-------+\n\
             |       |\n\
             |       O\n\
             |      /|\n\
             |\n\
             |\n");
    break;
    case 4:
      printf("\
             +-------+\n\
             |       |\n\
             |       O\n\
             |      /|\\\n\
             |\n\
             |\n");
    break;
    case 5:
      printf("\
             +-------+\n\
             |       |\n\
             |       O\n\
             |      /|\\\n\
             |        \\\n\
             |\n");
    break;
    case 6:
      printf("\
             +-------+\n\
             |       |\n\
             |       O\n\
             |      /|\\\n\
             |      / \\\n\
             |\n");
    break;
  }
}
