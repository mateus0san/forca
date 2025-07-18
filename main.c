#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "lib/forca.h" // cabeçalho para lidar com a lógica da forca
#include "lib/menu.h"  // cabeçalho para o menu - LINHA ADICIONADA
#include <conio.h> // para getch() e outras funções de console

int jogar_novamente(void);

int main(int argc, const char *const argv[])
{
    system("cls");
    system("chcp 65001"); // para suportar UTF-8 no console do Windows
    clrscr(); // limpa a tela do console

    // útil para gerar números mais 'aleatórios' com rand()
    srand(time(NULL));

    // LOOP PRINCIPAL MODIFICADO
    while (1) {
        // Exibe o menu e obtém a categoria escolhida
        int categoria = menu_principal();

        if (categoria == 0) {
            break; // Sai do programa se o usuário escolher sair
        }

        // Se chegou aqui, o usuário escolheu uma categoria (1-3)
        do {
            // retorna dados necessários para um novo jogo com a categoria específica
            struct ForcaGame game_dados = forca_dados_novo_jogo_categoria(categoria);

            forca_jogar(game_dados);

            free_ForcaGame(game_dados);
        } while (jogar_novamente());
    }

    return 0; // Programa encerra aqui quando usuário escolhe "Sair"
}

// FUNÇÃO MODIFICADA - agora retorna ao menu em vez de sair
int jogar_novamente(void)
{
    gotoxy(30,24);
    printf("Você quer jogar novamente? [s/n]:  ");

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
