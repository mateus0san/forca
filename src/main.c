#include <stdio.h>
#include <string.h>
#include "forca.h" // cabaçalho para lidar com a lógica da forca


int main(void) {
  const char **lista_palavras = forca_arquivo_carregar_fallback();

  // test para a lista de palavras, isso será removido
  for (int i = 0; strcmp(lista_palavras[i], "") != 0; i++) {
    printf("%s\n", lista_palavras[i]);
  }

}
