#include "forca_draw.h"
#include <stdio.h>
#include "forca_system.h"

static void forca(int errors);

void forca_draw(struct Draw *draw) {
  clear_screen();
  printf("----------------------%s------------------------\n",draw->tip) ;
    forca(draw->errors);
    printf("erros: %d\n", draw->errors);
    printf("chutes: %s\n", draw->guesses);
    printf("Palavra: %s\n", draw->unknown_word);
}

void forca_draw_won(char *word) {
    printf("\n\
###############################\n\
you won! the word was: %s\n\
###############################\n", word);
}
void forca_draw_lost(char *word) {
    printf("\n\
###############################\n\
you lost! the word was: %s\n\
###############################\n", word);
}

static void forca(int errors) {
    switch (errors)
    {
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
