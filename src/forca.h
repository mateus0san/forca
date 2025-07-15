/**
 * @file forca.h
 * @brief Contém as funções para rodar o jogo e uma struct básica
*/
#ifndef FORCA_H
#define FORCA_H

/**
 * @brief Struct com dados básicos do jogo.
*/
struct ForcaGame {
  char **word_list;  ///< Lista de palavras
  char *tip;         ///< Nome do arquivo como dica 
  int n_words;       ///< Quantidade de palavras
};

/**
 * @brief Deve receber um contador de argumentos e um vetor de argumentos. O
 * vetor de argumentos, opcionalmente, conterá o nome de um arquivo que possurirá
 * uma lista de palavras. Caso não haja arquivos válidos, solicitará em execução
 * o nome de um arquivo.
 * 
 * @param argc Número de argumentos.
 * @param argv Vetor de argumentos.
 * @return Retornará um ponteiro para um struct ForcaGame que foi alocada
 * dinamicamente. O usuário precisará desalocar usando a função free_ForcaGame().
 */
struct ForcaGame *forca_get_data(int argc, char *argv[]);

/**
 * @brief Controla funções para iniciar o jogo com uma struct ForcaGame
 * retornada por forca_get_data().
 * @param game_data Ponteiro para struct ForcaGame
*/
void forca_start_game(struct ForcaGame *game_data);

/**
 * @brief Desaloca a memória alocada por forca_get_data(). 
 * @param game_data Ponteiro para struct ForcaGame
*/
void free_ForcaGame(struct ForcaGame *game_data);

#endif
