/* forca_desenha é responsável por mostrar informações do jogo */

#include "lib/windows_linux.h"
#include "lib/forca_desenha.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "conio.h" // para manipulação de console
#include "gconio.h" // para manipulação de console

static void forca(int);
static char *new_palavra_desconhecida(char *); // trata a palavra secreta

void forca_desenha(struct ForcaDesenha *desenha_dados)
{
    int menu_principal(void) {
    int opcao;

    do {
        exibir_menu_principal();
        opcao = obter_opcao();

        switch (opcao) {
            case 1:
                if (escolher_categoria() == 1) {
                    return 1; // Retorna 1 para indicar que o usuário quer jogar
                }
                break;
            case 2:
                mostrar_instrucoes();
                break;
            case 3:
                system("cls");
                printf("Obrigado por jogar! Ate logo!\n");
                pausar();
                return 0; // Retorna 0 para sair do programa
            default:
                printf("Opcao invalida! Tente novamente.\n");
                pausar();
                break;
        }
    } while (1);
}

void exibir_menu_principal(void) {
    system("cls");

    printf("1. Jogar\n");
    printf("2. Instrucoes\n");
    printf("3. Sair\n");
    printf("Escolha uma opcao: ");
}

int escolher_categoria(void) {
    int opcao;

    do {
        exibir_menu_categorias();
        opcao = obter_opcao();

        switch (opcao) {
            case 1:
            case 2:
            case 3:
                return 1; // Categoria escolhida, prosseguir com o jogo
            case 0:
                return 0; // Voltar ao menu principal
            default:
                printf("Opcao invalida! Tente novamente.\n");
                pausar();
                break;
        }
    } while (1);
}

void exibir_menu_categorias(void) {
    system("cls");

    printf("=== CATEGORIAS DISPONIVEIS ===\n");
    printf("1. programacao\n");
    printf("2. animais\n");
    printf("3. tecnologia\n");
    printf("0. Voltar ao menu principal\n");
    printf("===============================\n");
    printf("\n");
    printf("Escolha uma categoria (0-3): ");
}

int obter_opcao(void) {
    int opcao;

    if (scanf("%d", &opcao) != 1) {
        // Limpa o buffer em caso de entrada inválida
        while (getchar() != '\n');
        return -1;
    }

    // Limpa o buffer
    while (getchar() != '\n');

    return opcao;
}

void mostrar_instrucoes(void) {
    system("cls");

    printf("========================================\n");
    printf("            INSTRUCOES\n");
    printf("========================================\n");
    printf("\n");
    printf("COMO JOGAR:\n");
    printf("1. O computador escolhera uma palavra aleatoria\n");
    printf("2. Voce deve adivinhar a palavra letra por letra\n");
    printf("3. Voce pode chutar uma letra ou a palavra inteira\n");
    printf("4. Voce tem 6 tentativas incorretas antes de perder\n");
    printf("5. Ganhe adivinhando todas as letras ou a palavra completa\n");
    printf("\n");
    printf("DICAS:\n");
    printf("- Use apenas letras (a-z)\n");
    printf("- Espacos sao permitidos em palavras compostas\n");
    printf("- O jogo nao diferencia maiusculas de minusculas\n");
    printf("\n");
    printf("Pressione qualquer tecla para voltar ao menu...");
    getch();
}

void pausar(void) {
    printf("Pressione qualquer tecla para continuar...");
    getch();
}


    system("cls");
    gotoxy(30,1);printf(" ███████████    ███████    ███████████     █████████    █████████");
    gotoxy(30,2);printf("░░███░░░░░░█  ███░░░░░███ ░░███░░░░░███   ███░░░░░███  ███░░░░░███");
    gotoxy(30,3);printf(" ░███   █ ░  ███     ░░███ ░███    ░███  ███     ░░░  ░███    ░███");
    gotoxy(30,4);printf(" ░███████   ░███      ░███ ░██████████  ░███          ░███████████");
    gotoxy(30,5);printf(" ░███░░░█   ░███      ░███ ░███░░░░░███ ░███          ░███░░░░░███");
    gotoxy(30,6);printf(" ░███  ░    ░░███     ███  ░███    ░███ ░░███     ███ ░███    ░███");
    gotoxy(30,7);printf("  █████       ░░░███████░   █████   █████ ░░█████████  █████   █████");
    gotoxy(30,8);printf("░░░░░          ░░░░░░░    ░░░░░   ░░░░░   ░░░░░░░░░  ░░░░░   ░░░░░");
    gotoxy(30,10);printf("----------------------%s---------------------------------------", desenha_dados->dica);
    forca(desenha_dados->erros);
    gotoxy(30,20);printf("erros: %d\n", desenha_dados->erros);
    gotoxy(30,21);printf("chutes: %s\n", desenha_dados->chutes);
    gotoxy(30,22);printf("Palavra: %s\n", desenha_dados->palavra_desconhecida);
}

void forca_desenhe_venceu(char *palavra)
{
        gotoxy(30,24);printf("\n\n\
                                ###############################\n\
                                voce venceu. a palavra era: %s\n\
                                ###############################\n", palavra);
}

void forca_desenhe_perdeu(char *palavra)
{
        gotoxy(30,24);printf("\n\n\
                                ###############################\n\
                                 voce perdeu. a palavra era: %s\n\
                                ###############################\n", palavra);
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
        gotoxy(30,12);printf("+-------+\n\
                              |       |\n\
                              |\n\
                              |\n\
                              |\n\
                              |\n");
        break;
    case 1:
        gotoxy(30,12);printf("+-------+\n\
                              |       |\n\
                              |       O\n\
                              |\n\
                              |\n\
                              |\n");
        break;
    case 2:
        gotoxy(30,12);printf("+-------+\n\
                              |       |\n\
                              |       O\n\
                              |       |\n\
                              |\n\
                              |\n");
        break;
    case 3:
        gotoxy(30,12);printf("+-------+\n\
                              |       |\n\
                              |       O\n\
                              |      /|\n\
                              |\n\
                              |\n");
        break;
    case 4:
        gotoxy(30,12);printf("+-------+\n\
                              |       |\n\
                              |       O\n\
                              |      /|\\\n\
                              |       |\n\
                              |\n");
        break;
    case 5:
        gotoxy(30,12);printf("+-------+\n\
                              |       |\n\
                              |       O\n\
                              |      /|\\\n\
                              |        \\\n\
                              |\n");
        break;
    case 6:
        gotoxy(30,12);printf("+-------+\n\
                              |       |\n\
                              |       O\n\
                              |      /|\\\n\
                              |      / \\\n\
                              |\n");
        break;
    }
}
