/**
 * @file forca.h
 * @brief Contém as funções para rodar o jogo e uma struct básica
*/
#ifndef FORCA_H
#define FORCA_H

/**
 * @brief Struct com dados básicos do jogo
*/
struct ForcaGame {
  char **word_list;  ///< Lista de palavras
  char *tip;         ///< Nome do arquivo como dica 
  int n_words;       ///< Quantiade de palavras
};

/**
 * @brief Lida com os argumentos para inicializa o jogo da forca.
 * 
 * @param argc Número de argumentos.
 * @param argv Vetor de argumentos.
 * @return Ponteiro para struct ForcaGame alocada dinamicamente.
 */
struct ForcaGame *forca_get_data(int argc, char *arg[]);

/**
 * @brief Controla funções para iniciar o jogo
 * @param game_data ponteiro para struct ForcaGame
*/
void forca_start_game(struct ForcaGame *game_data);

/**
 * @brief Desaloca a memória alocada por forca_get_data 
 * @param Ponteiro para struct ForcaGame
*/
void free_ForcaGame(struct ForcaGame *);

#endif
