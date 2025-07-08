#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "forca.h" // cabaçalho para lidar com a lógica da forca


int main(int argc, char *argv[]) {
  // útil para gerar números mais 'aleatórios' com rand()
  srand(time(NULL));

  const char *const *lista_palavras = forca_arquivo_carregar_lista(argc, argv);

  // test para a lista de palavras, isso será removido
  for (int i = 0; strcmp(lista_palavras[i], "") != 0; i++) {
    printf("%s\n", lista_palavras[i]);
  }

}
