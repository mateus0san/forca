#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <MMsystem.h>
#include <conio.h>
#include "gconio.h"
#include <string.h>


int main()
{
    // ativação do gconio no programa //
    system("cls");
    system("chcp 65001");
    textbackground(BLACK);
    textcolor(WHITE);
    clrscr();
    int opcao;
    do
    {
        gotoxy(30,1);printf(" ███████████    ███████    ███████████     █████████    █████████");
        gotoxy(30,2);printf("░░███░░░░░░█  ███░░░░░███ ░░███░░░░░███   ███░░░░░███  ███░░░░░███");
        gotoxy(30,3);printf(" ░███   █ ░  ███     ░░███ ░███    ░███  ███     ░░░  ░███    ░███");
        gotoxy(30,4);printf(" ░███████   ░███      ░███ ░██████████  ░███          ░███████████");
        gotoxy(30,5);printf(" ░███░░░█   ░███      ░███ ░███░░░░░███ ░███          ░███░░░░░███");
        gotoxy(30,6);printf(" ░███  ░    ░░███     ███  ░███    ░███ ░░███     ███ ░███    ░███");
        gotoxy(30,7);printf("  █████       ░░░███████░   █████   █████ ░░█████████  █████   █████");
        gotoxy(30,8);printf("░░░░░          ░░░░░░░    ░░░░░   ░░░░░   ░░░░░░░░░  ░░░░░   ░░░░░");

        gotoxy(50,13);printf("╔═════════════════════════╗\n");
        gotoxy(50,14);printf("║   ESCOLHA UMA OPCAO     ║ ");
        gotoxy(50,15);printf("║   [1] - INICIO          ║ ");
        gotoxy(50,16);printf("║   [2] - REGRAS          ║ ");
        gotoxy(50,17);printf("║   [0] - SAIR            ║ ");
        gotoxy(50,18);printf("║   OPCAO:                ║ ");
        gotoxy(50,19);printf("╚═════════════════════════╝\n");
        gotoxy(60,18);scanf("%d", &opcao);

        system("cls");
        // switch criado para armazenar as opcoes que o usuario tem //
        switch (opcao)
        {
        case 1:
           printf("jogo");
            break;
        case 2:
           printf("regras");
            break;
        case 0:

            gotoxy(40,6);printf("¯AGRADECIMENTOS...!");
            gotoxy(40,7);printf("¯!");
            gotoxy(40,8);printf("¯DESENVOLVIDO POR!");
            gotoxy(40,9);printf("¯MATEUS SANTOS ARAUJO SANTIAGO!");
            gotoxy(40,10);printf("¯WALLACE DA SILVA BARRETO!");
            gotoxy(40,11);printf("¯WALLACE GABRIEL SANTOS DE JESUS!");
            gotoxy(40,12);printf("¯ALAN FERNANDES BISPO DO NASCIMENTO!");
            gotoxy(40,13);printf("¯RYAN GUILHERME MOURA MARTIS!");
            gotoxy(40,14);printf("¯JHONES SANTIAGO GOIS!");
            gotoxy(40,20);printf("Saindo do programa...!\n");
            gotoxy(40,21);printf("Pressione ENTER para sair...");
            break;
        default:
            printf("Opcao invalida!\n\n");
            break;
        }
        getchar();
        getchar();
        system("cls");


    }
    while (opcao != 0);
    return 0;
}


