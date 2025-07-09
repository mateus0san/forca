#include <stdlib.h>
#include <time.h>
#include "forca.h" // cabaçalho para lidar com a lógica da forca


int main(int argc, char *argv[]) {
  // útil para gerar números mais 'aleatórios' com rand()
  srand(time(NULL));

  // retorna dados necessários para um novo jogo
  struct ForcaGame game_dados = forca_arquivo_dados_novogame(argc, argv);

  forca_desenhe(game_dados);
}

