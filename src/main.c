#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "forca.h" // cabaçalho para lidar com a lógica da forca


int main(int argc, char *argv[]) {
  // útil para gerar números mais 'aleatórios' com rand()
  srand(time(NULL));

  struct ForcaGame game_dados = forca_arquivo_carregar_lista(argc, argv);

  // Testes
  printf("palavra: %s\n", game_dados.palavra_dados.palavra);
  printf("dica: %s\n", game_dados.palavra_dados.dica);
  printf("acertos: %d\n", game_dados.numero_acertos);
  printf("erros: %d\n", game_dados.numero_errors);
  printf("chutes: %s", game_dados.caracteres_chutados);

}
