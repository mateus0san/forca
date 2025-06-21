#include <stdlib.h>
#include <time.h>
#include "forca.h"

int main(int argc, char *argv[]) {
  srand(time(NULL));

  char *file_name, *word;

  if ((file_name = get_file(argc, argv)) == NULL) {
    exit(EXIT_FAILURE);
  }

  if ((word = get_word(file_name)) == NULL) {
    exit(EXIT_FAILURE);
  }

  start_game(file_name, word);
  
}

