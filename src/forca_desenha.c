/* forca_desenha é responsável por mostrar informações do jogo */

#include "windows_linux.h"
#include "forca_desenha.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static void forca(int);
static char *new_palavra_desconhecida(char *); // trata a palavra secreta

void forca_desenha(struct ForcaDesenha *desenha_dados)
{
    clear_screen();
    printf("----------------------%s------------------------\n", desenha_dados->dica);
    forca(desenha_dados->erros);
    printf("erros: %d\n", desenha_dados->erros);
    printf("chutes: %s\n", desenha_dados->chutes);
    printf("Palavra: %s\n", desenha_dados->palavra_desconhecida);
}

void forca_desenhe_venceu(char *palavra)
{
    printf("\n\n\
###############################\n\
você venceu! a palavra era: %s\n\
###############################\n", palavra);
printf("\n\n----------------------FIM DE JOGO------------------------\n");
}

void forca_desenhe_perdeu(char *palavra)
{
    printf("\n\
###############################\n\
você perdeu! a palavra era: %s\n\
###############################\n", palavra);
printf("\n\n----------------------FIM DE JOGO------------------------\n");
}

struct ForcaDesenha *forca_desenha_new_ForcaDesenha(struct ForcaGame game_dados)
{
    struct ForcaDesenha *desenha_dados;

    desenha_dados = malloc(sizeof(struct ForcaDesenha));
    desenha_dados->palavra_desconhecida = new_palavra_desconhecida(game_dados.palavra);
    desenha_dados->dica = game_dados.dica;
    desenha_dados->chutes[0] = '\0';
    desenha_dados->erros = 0;

    return desenha_dados;
}

void forca_desenha_free_ForcaDesenha(struct ForcaDesenha *dados)
{
    free(dados->palavra_desconhecida);
    // para que não aponte para ponteiros que foram desalocados com free
    dados->dica = NULL;

    free(dados);
}

static char *new_palavra_desconhecida(char *palavra)
{
    int len_palavra = strlen(palavra);
    char *esconder_palavra = malloc(len_palavra + 1);

    for (int i = 0; i < len_palavra; i++)
    {
        esconder_palavra[i] = (palavra[i] == ' ') ? ' ' : '_';
    }

    esconder_palavra[len_palavra] = '\0';

    return esconder_palavra;
}

// desenha a forca
static void forca(int erros)
{
    switch (erros)
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

