#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "forca.h" // cabaçalho para lidar com a lógica da forca

void forca_desenhe(struct ForcaGame);

int main(int argc, char *argv[]) {
  // útil para gerar números mais 'aleatórios' com rand()
  srand(time(NULL));

  // retorna dados necessários para um novo jogo
  struct ForcaGame game_dados = forca_arquivo_dados_novogame(argc, argv);

  forca_desenhe(game_dados);
}

void forca_desenhe(struct ForcaGame game_dados) {
  printf("palavra: %s\n", game_dados.palavra_dados.palavra);
  printf("dica: %s\n", game_dados.palavra_dados.dica);
  printf("acertos: %d\n", game_dados.numero_acertos);
  printf("erros: %d\n", game_dados.numero_erros);
  printf("chutes: %s\n", game_dados.caracteres_chutados);
}
