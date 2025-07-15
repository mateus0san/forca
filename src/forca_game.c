/**
 * @file forca_game.c
 * @brief Define a lógica do jogo
*/
#include "forca.h"
#include <stdio.h>
#include <string.h>
#include "forca_draw.h"
#include "forca_system.h"
#include <stdlib.h>
#include <ctype.h>

/**
 * @brief Dado um struct ForcaGame, retorna uma palavra da lista
 * @param game_data Ponteiro para uma struct ForcaGame
 * @return Ponteiro para uma palavra
*/
static char *get_random_word(struct ForcaGame *);

/**
 * @brief inicia o jogo
 * @param word Ponteiro para uma palavra
 * @param tip Ponteiro para uma dica
*/ 
static void start_game(char *word, char *tip);

/**
 * @brief inicializa uma struct Draw
 * @param word Ponteiro palavra
 * @param tip Ponteiro para dica
 * @return Ponteiro para uma struct Draw
*/
static struct Draw *new_Draw(char *word, char *tip);

/**
 * @brief Identifica o tipo de chute, se é uma palavra ou um char
 * @param draw Ponteiro para struct Draw
 * @param guess Ponteiro para palavra chutada
 * @return Inteiro indicado o status do jogo
*/
static int take_guesses(struct Draw *draw, char *guess);

/**
 * @brief Verifica se a palavra chutada é correta
 * @param guess Ponteiro para string chutada pelo usuário
 * @param draw Ponteiro para struct Draw
 * @param word Ponteiro para a palavra que precisa ser addivinhada do jogo atual
*/
static void guessed_word(char *guess, struct Draw *draw, char *word);

/**
 * @brief Verifica se o char chutado esta na palavra
 * @param guess char chutado
 * @param draw Ponteiro para struct Draw
 * @param word Ponteiro para a palavra que precisa ser adivinhada do jogo atual 
*/
static void guessed_char(char guess, struct Draw *draw, char *word); 

/**
 * @brief Verifica se a unknown_word é igual a word
 * @param draw Ponteiro para struct Draw
 * @param word Ponteiro para palavra do jogo atual
 * @return Retorna um Inteiro idicando se a palavra já foi adivinhada
*/
static int verify_status(struct Draw *draw, char *word); 

/**
 * @brief Pergunta se quer jogar novamente
 * @return Retorna um inteiro idiciando sim ou não
*/
static int play_again(void);

/**
 * @brief Libera a memória alacada de uma struct Draw
 * @param draw Ponteiro para struct Draw
*/
static void free_Draw(struct Draw *draw);


void forca_start_game(struct ForcaGame *game_data) {
  do {
    char *word = get_random_word(game_data);

    for (int i = 0; word[i] != '\0'; i++)
      word[i] = tolower(word[i]);

    start_game(word, game_data->tip);
    free(word);
  } while (play_again());
}

static char *get_random_word(struct ForcaGame *game_data) {
  int i = rand() % game_data->n_words;

  char *word = system_malloc(strlen(game_data->word_list[i]) + 1);

  strcpy(word, game_data->word_list[i]);

  return word;
}

static void start_game(char *word, char *tip) {
  struct Draw *draw = new_Draw(word, tip);
  int cond = 0;
  do {
    forca_draw(draw);
    cond = take_guesses(draw, word);
  } while (!cond); 

  free_Draw(draw);
}

static struct Draw *new_Draw(char *word, char *tip) {
  struct Draw *draw = system_malloc(sizeof(struct Draw)); 

  char *unknown_word = system_malloc(strlen(word) + 1);

  int i;
  for (i = 0; word[i] != '\0'; i++) {
    if (word[i] == ' ')
      unknown_word[i] = ' ';
    else
      unknown_word[i] = '_';
  }
  unknown_word[i] = '\0';

  char *tip_draw = system_malloc(strlen(tip) + 1);
  strcpy(tip_draw, tip);


  draw->unknown_word = unknown_word;
  draw->tip = tip_draw;
  draw->errors = 0;
  draw->guesses[0] = '\0';

  return draw;
}

static int take_guesses(struct Draw *draw, char *word) {
  size_t size = 0;
  char *line = NULL;

  printf("Guess: ");
  int size_str = getline(&line, &size, stdin) - 1;

  if (size_str < 0) {
    exit(0);
  }

  line[size_str] = '\0';

  for (int i = 0; line[i] != '\0'; i++)
    line[i] = tolower(line[i]);

  if (size_str > 1) 
    guessed_word(line, draw, word);
  else if (size_str == 1) 
    guessed_char(line[0], draw, word);
  else 
    return 0;

  free(line);

  return verify_status(draw, word);
}

static void guessed_word(char *line, struct Draw *draw, char *word) {
  if (strcmp(line, word) == 0)
    strcpy(draw->unknown_word, word);
  else
    draw->errors += strlen(line);
} 

static void guessed_char(char c, struct Draw *draw, char *word) {
  int i;
  for (i = 0; draw->guesses[i] != '\0'; i++) {
    if (draw->guesses[i] == c) {
      printf("You have typed this char before '%c'\n", c);
      system_pause();
      return;
    }
  }

  draw->guesses[i++] = c;
  draw->guesses[i] = '\0';

  int count = 0;
  for (int i = 0; word[i] != '\0'; i++)
    if (word[i] == c) {
      draw->unknown_word[i] = c;
      count++;
    }

  if (count == 0)
    draw->errors++;
}

#define MAX_NUMBER_ERRORS 6
static int verify_status(struct Draw *draw, char *word) {
  if (strcmp(draw->unknown_word, word) == 0) {
    forca_draw_won(word);
    return 1;
  }
  if (draw->errors >= MAX_NUMBER_ERRORS) {
    forca_draw_lost(word);
    return 1;
  }
  return 0;
}

static int play_again(void) {
  int c, op;

  printf("Play again? [y/n] ");
  while ((c = getc(stdin)) != EOF && c != '\n') 
    op = c;

  if (c == EOF)
    return 0;

  return (op == 'y' || op == 'Y') ? 1 : 0;
}

static void free_Draw(struct Draw *draw) {
  free(draw->tip);
  free(draw->unknown_word);
  free(draw);
}
