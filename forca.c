#include "forca.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 50
#define MAX_WORD_SIZE 50

char *get_file(int argc, char *argv[]) {
  if (--argc < 1) {
    fprintf(stderr, "Forca: bad usage\n");
    return NULL;
  }

  int index = (rand() % argc) + 1;
  int len = strlen(argv[index]);

  if (len >= 50 || len == 0) {
    fprintf(stderr, "Forca: invalid argument: %s\n", argv[index]);
    return NULL;
  }

  return argv[index];
}

int read_words(FILE *fi, char **words) {
  int word_counter = 0;

  for (int i = 0; i < MAX_WORDS; i++) {
    if ((words[i] = malloc(MAX_WORD_SIZE)) == NULL) {
      fprintf(stderr, "Forca: malloc error\n");
      return word_counter;
    }

    if (fgets(words[i], MAX_WORD_SIZE, fi) == NULL) {
      return word_counter;
    }
    word_counter++;
  }
  return word_counter;
}

char *choose_word(char **words, int n, const char *file_name) {

  int index = (rand() % n);

  int len;
  for (len = 0; len < MAX_WORD_SIZE; len++) {
    if (words[index][len] == '\n') {
      words[index][len] = '\0';
      break;
    }
    words[index][len] = tolower(words[index][len]);
  }

  if (++len < 1) {
    fprintf(stderr, "Forca: invalid word in %s", file_name);
    return NULL;
  }
  
  return words[index];
}

void free_words(char *words[], int n_words, char *word) {
  for (int i = 0; i < n_words; i++) {
    if (word != words[i]) {
      free(words[i]);
    }
  }
  free(words);
}

char *get_word(const char *file_name) {
  FILE *fi;

  if ((fi = fopen(file_name, "r")) == NULL) {
    fprintf(stderr, "Forca: failed to open %s", file_name);
    return NULL;
  }

  char **words = malloc(MAX_WORDS * sizeof(char **));
  int n_words;
  if ((n_words = read_words(fi, words)) == 0) {
    fprintf(stderr, "Forca: can't read words in %s", file_name);
  }

  char *return_word = choose_word(words, n_words, file_name);

  free_words(words, n_words, return_word);

  return return_word;
}
void drawn_hangman(int misses) {
  switch (misses) {
    case 0:
      printf("\
             +-------+\n\
             |       |\n\
             |\n\
             |\n\
             |\n\
             |\n");
    break;
    case 1:
      printf("\
             +-------+\n\
             |       |\n\
             |       O\n\
             |\n\
             |\n\
             |\n");
    break;
    case 2:
      printf("\
             +-------+\n\
             |       |\n\
             |       O\n\
             |       |\n\
             |\n\
             |\n");
    break;
    case 3:
      printf("\
             +-------+\n\
             |       |\n\
             |       O\n\
             |      /|\n\
             |\n\
             |\n");
    break;
    case 4:
      printf("\
             +-------+\n\
             |       |\n\
             |       O\n\
             |      /|\\\n\
             |\n\
             |\n");
    break;
    case 5:
      printf("\
             +-------+\n\
             |       |\n\
             |       O\n\
             |      /|\\\n\
             |        \\\n\
             |\n");
    break;
    case 6:
      printf("\
             +-------+\n\
             |       |\n\
             |       O\n\
             |      /|\\\n\
             |      / \\\n\
             |\n");
    break;
  }
}
void start_game(const char *file_name, const char *word) {

  int right = 0, wrong = 0;
  int len = strlen(word);
  char *unknown_word = malloc(len);

  memset(unknown_word, '_', len);
  for (int i = 0; i < len; i++) {
    if (word[i] == ' ')
      unknown_word[i] = ' ';
  }
  unknown_word[len] = '\0';

  for (int i = 0; i <  6; i++) {
  system("clear");
  printf("%s -> %s\n", file_name, word);
  printf("-------%s-------\n", file_name);
  drawn_hangman(++wrong);

  printf("%s\n", unknown_word);

  printf("\nacertos: %d\nerros: %d\n", right, wrong);
  system("sleep 3");
}
}
