#include <stdlib.h>
#include <time.h>
#include "lib/forca.h" // cabaçalho para lidar com a lógica da forca


int main(int argc, const char *const argv[]) {
  // útil para gerar números mais 'aleatórios' com rand()
  srand(time(NULL));

  // retorna dados necessários para um novo jogo
  struct ForcaGame game_dados = forca_dados_novo_jogo(argc, argv);

  forca_jogar(game_dados);
}

