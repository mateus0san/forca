#include "forca.h"
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    // 1) Semente para o gerador de números aleatórios
    srand((unsigned)time(NULL));

    // 2) Prepara a estrutura de dados do jogo a partir dos argumentos
    //    (palavras, número máximo de erros, etc.)
    struct ForcaGame *game_data = forca_get_data(argc, argv);

    // 3) Inicia o loop principal do jogo
    //    (desenha a forca, recebe palpite, atualiza estado)
    forca_start_game(game_data);

    // 4) Libera toda a memória alocada para o jogo
    free_ForcaGame(game_data);

    // 5) Retorna código de sucesso
    return EXIT_SUCCESS;
}
