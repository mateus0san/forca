/**
 * @file forca_draw.h
 * @brief Possui declarações para desenhar o jogo
*/
#ifndef FORCA_DRAWN_H
#define FORCA_DRAWN_H

/**
 * @brief Struct que armazena infomações do estado da forca
*/
struct Draw {
  char *unknown_word; ///< Palavra desconhecida
  char guesses[127];  ///< Caracteres chutados pelo úsuario
  char *tip;          ///< dica (nome do arquivo)
  int errors;         ///< numero de erros
};

/**
 * @brief Imprime o estado da forca
 * @param draw Ponteiro para struct Draw
*/
void forca_draw(struct Draw *);

/**
 * @brief Imprimi na tela 'you won'
 * @param word palavra
*/
void forca_draw_won(char *word); 

/**
 * @brief Imprimi na tela 'you lost'
 * @param word palavra
*/
void forca_draw_lost(char *word); 

#endif
