#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "lib/windows_linux.h"

// Declaração das funções do menu
void exibir_menu_principal(void);
void exibir_menu_categorias(void);
int obter_opcao(void);
void mostrar_instrucoes(void);
void pausar(void);
int escolher_categoria(void);

// Função principal do menu
int menu_principal(void) {
    int opcao;

    do {
        exibir_menu_principal();
        opcao = obter_opcao();

        switch (opcao) {
            case 1:
                return escolher_categoria(); // Retorna a categoria escolhida (1-3) ou 0 para voltar
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
    gotoxy(30,1);printf(" ███████████    ███████    ███████████     █████████    █████████");
    gotoxy(30,2);printf("░░███░░░░░░█  ███░░░░░███ ░░███░░░░░███   ███░░░░░███  ███░░░░░███");
    gotoxy(30,3);printf(" ░███   █ ░  ███     ░░███ ░███    ░███  ███     ░░░  ░███    ░███");
    gotoxy(30,4);printf(" ░███████   ░███      ░███ ░██████████  ░███          ░███████████");
    gotoxy(30,5);printf(" ░███░░░█   ░███      ░███ ░███░░░░░███ ░███          ░███░░░░░███");
    gotoxy(30,6);printf(" ░███  ░    ░░███     ███  ░███    ░███ ░░███     ███ ░███    ░███");
    gotoxy(30,7);printf("  █████       ░░░███████░   █████   █████ ░░█████████  █████   █████");
    gotoxy(30,8);printf("░░░░░          ░░░░░░░    ░░░░░   ░░░░░   ░░░░░░░░░  ░░░░░   ░░░░░");
    gotoxy(85,10);printf("     _______\n");
    gotoxy(85,11);printf("    |/      |\n");
    gotoxy(85,12);printf("    |      (_)\n");
    gotoxy(85,13);printf("    |      \\|/\n");
    gotoxy(85,14);printf("    |       |\n");
    gotoxy(85,15);printf("    |      / \\\n");
    gotoxy(85,16);printf("    |\n");
    gotoxy(85,17);printf(" ___|___\n\n");
    gotoxy(50,10);printf("╔══════════════════════╗\n");
    gotoxy(50,11);printf("║ 1. Jogar             ║");
    gotoxy(50,12);printf("║ 2. Instrucoes        ║");
    gotoxy(50,13);printf("║ 3. Sair              ║");
    gotoxy(50,14);printf("║ Escolha uma opcao:   ║");
    gotoxy(50,15);printf("╚══════════════════════╝\n");
}

int escolher_categoria(void) {
    int opcao;

    do {
        exibir_menu_categorias();
        opcao = obter_opcao();

        switch (opcao) {
            case 1:
                return 1; // Retorna 1 para programação
            case 2:
                return 2; // Retorna 2 para animais
            case 3:
                return 3; // Retorna 3 para tecnologia
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
    gotoxy(30,1);printf(" ███████████    ███████    ███████████     █████████    █████████");
    gotoxy(30,2);printf("░░███░░░░░░█  ███░░░░░███ ░░███░░░░░███   ███░░░░░███  ███░░░░░███");
    gotoxy(30,3);printf(" ░███   █ ░  ███     ░░███ ░███    ░███  ███     ░░░  ░███    ░███");
    gotoxy(30,4);printf(" ░███████   ░███      ░███ ░██████████  ░███          ░███████████");
    gotoxy(30,5);printf(" ░███░░░█   ░███      ░███ ░███░░░░░███ ░███          ░███░░░░░███");
    gotoxy(30,6);printf(" ░███  ░    ░░███     ███  ░███    ░███ ░░███     ███ ░███    ░███");
    gotoxy(30,7);printf("  █████       ░░░███████░   █████   █████ ░░█████████  █████   █████");
    gotoxy(30,8);printf("░░░░░          ░░░░░░░    ░░░░░   ░░░░░   ░░░░░░░░░  ░░░░░   ░░░░░");
    gotoxy(50,10);printf("╔═══════════════════════════════╗\n");
    gotoxy(50,11);printf("║    CATEGORIAS DISPONIVEIS     ║");
    gotoxy(50,12);printf("║ 1. programacao                ║");
    gotoxy(50,13);printf("║ 2. animais                    ║");
    gotoxy(50,14);printf("║ 3. tecnologia                 ║");
    gotoxy(50,15);printf("║ 0. Voltar ao menu principal   ║");
    gotoxy(50,16);printf("║ Escolha uma categoria (0-3):  ║");
    gotoxy(50,17);printf("╚═══════════════════════════════╝\n");
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
    gotoxy(30,1);printf(" ███████████    ███████    ███████████     █████████    █████████");
    gotoxy(30,2);printf("░░███░░░░░░█  ███░░░░░███ ░░███░░░░░███   ███░░░░░███  ███░░░░░███");
    gotoxy(30,3);printf(" ░███   █ ░  ███     ░░███ ░███    ░███  ███     ░░░  ░███    ░███");
    gotoxy(30,4);printf(" ░███████   ░███      ░███ ░██████████  ░███          ░███████████");
    gotoxy(30,5);printf(" ░███░░░█   ░███      ░███ ░███░░░░░███ ░███          ░███░░░░░███");
    gotoxy(30,6);printf(" ░███  ░    ░░███     ███  ░███    ░███ ░░███     ███ ░███    ░███");
    gotoxy(30,7);printf("  █████       ░░░███████░   █████   █████ ░░█████████  █████   █████");
    gotoxy(30,8);printf("░░░░░          ░░░░░░░    ░░░░░   ░░░░░   ░░░░░░░░░  ░░░░░   ░░░░░");
    gotoxy(32,10);printf("╔═════════════════════════════════════════════════════════════╗\n");
    gotoxy(32,11);printf("║                        INSTRUCOES                           ║");
    gotoxy(32,12);printf("║ COMO JOGAR:                                                 ║");
    gotoxy(32,13);printf("║ 1. O computador escolhera uma palavra aleatoria             ║");
    gotoxy(32,14);printf("║ 2. Voce deve adivinhar a palavra letra por letra            ║");
    gotoxy(32,15);printf("║ 3. Voce pode chutar uma letra ou a palavra inteira          ║");
    gotoxy(32,16);printf("║ 4. Voce tem 6 tentativas incorretas antes de perder         ║");
    gotoxy(32,17);printf("║ 5. Ganhe adivinhando todas as letras ou a palavra completa  ║");
    gotoxy(32,18);printf("║                         DICAS:                              ║");
    gotoxy(32,19);printf("║ - Use apenas letras (a-z)                                   ║");
    gotoxy(32,20);printf("║ - Espacos sao permitidos em palavras compostas              ║");
    gotoxy(32,21);printf("║ - O jogo nao diferencia maiusculas de minusculas            ║");
    gotoxy(32,22);printf("║ Pressione qualquer tecla para voltar ao menu...             ║");
    gotoxy(32,23);printf("╚═════════════════════════════════════════════════════════════╝\n");
    getch();
}

void pausar(void) {
    printf("Pressione qualquer tecla para continuar...");
    getch();
}
