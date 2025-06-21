#include "forca.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 50
#define MAX_WORD_SIZE 50

char *get_file(int argc, char *argv[]) {
  argc--;
  if (argc < 1) {
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

char *choose_word(char **words, int n, char *file_name) {

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

char *get_word(char *file_name) {
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

  return choose_word(words, n_words, file_name);
}
