#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "lib/forca.h" // cabe�alho para lidar com a l�gica da forca
#include "lib/menu.h"  // cabe�alho para o menu - LINHA ADICIONADA
#include <conio.h> // para getch() e outras fun��es de console

int jogar_novamente(void);

int main(int argc, const char *const argv[])
{
    system("cls");
    system("chcp 65001"); // para suportar UTF-8 no console do Windows
    clrscr(); // limpa a tela do console

    // �til para gerar n�meros mais 'aleat�rios' com rand()
    srand(time(NULL));

    // LOOP PRINCIPAL MODIFICADO
    while (1) {
        // Exibe o menu e obt�m a categoria escolhida
        int categoria = menu_principal();

        if (categoria == 0) {
            break; // Sai do programa se o usu�rio escolher sair
        }

        // Se chegou aqui, o usu�rio escolheu uma categoria (1-3)
        do {
            // retorna dados necess�rios para um novo jogo com a categoria espec�fica
            struct ForcaGame game_dados = forca_dados_novo_jogo_categoria(categoria);

            forca_jogar(game_dados);

            free_ForcaGame(game_dados);
        } while (jogar_novamente());
    }

    return 0; // Programa encerra aqui quando usu�rio escolhe "Sair"
}

// FUN��O MODIFICADA - agora retorna ao menu em vez de sair
int jogar_novamente(void)
{
    gotoxy(30,24);
    printf("Voc� quer jogar novamente? [s/n]:  ");

    int c, op;
    while ((c = getc(stdin)) != EOF && c != '\n')
        op = c;
    if (c == EOF)
        return 0;
    if (op == 'S' || op == 's')
        return 1;

    // LINHA REMOVIDA: system("cls");
    return 0; // Volta ao menu principal em vez de sair do programa
}
