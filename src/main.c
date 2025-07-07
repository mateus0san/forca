#include <stdio.h>
#include <string.h>
#include "forca.h" // cabaçalho para lidar com a lógica da forca


int main(void) {
  // test para a lista de palavras PROGRAMACAO, isso será removido
  for (int i = 0; strcmp(forca_arquivo_prog_palavras[i], "") != 0; i++) {
    printf("%s\n", forca_arquivo_prog_palavras[i]);
  }

}
