#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "forca.h"

// funcao pergunta se voce quer jogar de novo
int play_again() {
  int c, op;
  printf("Voce quer jogar novamente? <s/n> ");
  while ((c = getc(stdin)) != EOF && c != '\n') {
    op = c;
  } 

  return ((op == 'S' || op == 's') && c == '\n') ? 1 : 0;
}

int main(int argc, char *argv[]) {
  srand(time(NULL));

  char *file_name, *word;

  do {
    if ((file_name = get_file(argc, argv)) == NULL) {
      exit(EXIT_FAILURE);
    }

    if ((word = get_word(file_name)) == NULL) {
      exit(EXIT_FAILURE);
    }

      system("clear");
      start_game(file_name, word);
      free(word);
  } while (play_again());  
}
