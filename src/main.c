#include <stdio.h>
#include <string.h>
#include "forca.h" // cabaçalho para lidar com a lógica da forca


int main(void) {
  // test para a lista de palavras PROGRAMACAO, isso será removido
  for (int i = 0; strcmp(PROGRAMACAO[i], "") != 0; i++) {
    printf("%s\n", PROGRAMACAO[i]);
  }

}
