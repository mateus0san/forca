#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 50
#define WORD_SIZE 50

void error(const char *);
void *handle_malloc(size_t);
char *get_file(int, char **);
char *get_word(char *);


int main(int argc, char *argv[]) {
  char *file_name, *word;

  file_name = get_file(argc, argv);
  word = get_word(file_name);

  return 0;
}

void *handle_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    error("malloc error");
  }

  return ptr;
}

char *get_word(char *file_name) {
  FILE *fi = fopen(file_name, "r");

  char **words = (char **) handle_malloc(MAX_WORDS * sizeof(char *));

  int c, count = 0;
  char word[WORD_SIZE];
  while ((c = getc(fi) != EOF) && count < 50) {
    if (!isalpha(c)) {
      error("unknow char");
    }
  }
}

char *get_file(int argc, char *list_files[]) {
  argc--;
  if (argc < 1) {
    error("bad usage\nUsage: forca arg1\n");
    return NULL;
  }

  srand(time(NULL));   
  int i = (rand() % argc) + 1;

  if (strlen(list_files[i]) == 0) {
    error("invalid argument\n");
    return NULL;
  } 

  return list_files[i];
}

void error(const char *msg_error) {
  fprintf(stderr, "forca: %s", msg_error);
}
