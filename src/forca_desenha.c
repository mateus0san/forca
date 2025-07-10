/* forca_desenha é responsável por mostrar informações do jogo */

#include "forca.h"
#include <stdio.h>
#include <stdlib.h>

static void clear_screen(); 
static void forca(int);


void forca_desenhe(struct ForcaGame game_dados) {
  clear_screen();
  printf("----------------------%s------------------------\n", game_dados.palavra_dados.dica);
  forca(game_dados.numero_erros);
  printf("acertos: %d\n", game_dados.numero_acertos);
  printf("erros: %d\n", game_dados.numero_erros);
  printf("chutes: %s\n", game_dados.caracteres_chutados);
  printf("Palavra: %s\n", game_dados.palavra_dados.ad_palavra);
  printf("%s\n", game_dados.palavra_dados.palavra);
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
static void forca(int error) {
  switch (error) {
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
