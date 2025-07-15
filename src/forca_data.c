#include "forca.h"
#include "system_compatible.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static struct ForcaGame *handle_args(int argc, char *argv[]);
static struct ForcaGame *type_file(void);
static struct ForcaGame *read_file(FILE *file, char *filename);
static void remove_breakline(char *word);
static char **read_word_list(FILE *file, char *filename, int n_words); 
static int count_words(FILE *file);
struct ForcaGame *forca_get_data(int argc, char *argv[]) {
  struct ForcaGame *game_data;

  // lida com argumentos da linha de comando
  game_data = handle_args(argc, argv);
  if (game_data != NULL)
    return game_data;

  // lida com arquivos informados em execução
  game_data = type_file();
  if (game_data != NULL)
    return game_data;
  
  fprintf(stderr, "forca: something wrong with handle_args or type_file\n");
  exit(1);
}

void free_ForcaGame(struct ForcaGame *game_data) {
  for (int i = 0; game_data->word_list[i] != NULL; i++)
    free(game_data->word_list[i]);
  free(game_data->tip);
  free(game_data->word_list);
  free(game_data);
}

static struct ForcaGame *handle_args(int argc, char *argv[]) {
  if (argc == 1) {
    fprintf(stderr, "forca: no arguments in command line.\n");
    return NULL;
}
  FILE *file = fopen(argv[1], "r");
  if (file == NULL) {
    fprintf(stderr, "forca: can't open the file %s\n", argv[1]);
    exit(1);
  }

  char *line = system_malloc(strlen(argv[1]) + 1);
  strcpy(line, argv[1]);

  return read_file(file, line); 
}

static struct ForcaGame *type_file(void) {
  size_t size = 0;
  char *line = NULL;

  printf("Enter the file name: ");
  if (getline(&line, &size, stdin) < 1) {
    fprintf(stderr, "forca: file name invalid\n");
    exit(1);
  }
  remove_breakline(line);

  FILE *file = fopen(line, "r");
  if (file == NULL) {
    fprintf(stderr, "forca: can't open the file %s\n", line);
    exit(1);
  }

  return read_file(file, line);
}

static struct ForcaGame *read_file(FILE *file, char *line) {
  struct ForcaGame *game_dados = system_malloc(sizeof(struct ForcaGame));

  int n_words = count_words(file);
  game_dados->word_list = read_word_list(file, line, n_words);
  if (game_dados->word_list == NULL) {
    fprintf(stderr, "forca: something wrong with read_word_list\n");
  }
  game_dados->tip = line;
  game_dados->n_words = n_words;

  fclose(file);

  return game_dados;
}

static char **read_word_list(FILE *file, char *file_name, int n_words) {
  if (n_words == 0) {
    fprintf(stderr, "forca: not valid words in %s\n", file_name);
    exit(1);
  }

  char **words_list = system_malloc((n_words + 1) * sizeof(char *));
  size_t size;
  int i;

  for (i = 0; i < n_words; i++) {
    words_list[i] = NULL;
    size = 0;
    if (getline(&(words_list[i]), &size, file) < 1) {
      free(words_list[i]);
      break;
    }
    remove_breakline(words_list[i]);
  }

  words_list[i] = NULL;
  if (words_list[0] == NULL) {
    fprintf(stderr, "forca: getline can't read words in %s\n", file_name);
    exit(1);
  }
  return words_list;
}

static void remove_breakline(char *word) {
  for (int i = 0; word[i] != '\0'; i++)
    if (word[i] == '\n') {
      word[i] = '\0';
      return;
    }
}

static int count_words(FILE *file) {
  int count_words = 0;
  int c; 

  while ((c = getc(file)) != EOF) {
    if (c == '\n')
      count_words++;
  }

  rewind(file);
  return count_words;
}
