#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "forca.h" // cabaçalho para lidar com a lógica da forca

int jogar_novamente(void);

int main(int argc, const char *const argv[]) {
  // útil para gerar números mais 'aleatórios' com rand()
  srand(time(NULL));

  do {
  // retorna dados necessários para um novo jogo
  struct ForcaGame game_dados = forca_dados_novo_jogo(argc, argv);

  forca_jogar(game_dados);

  free_ForcaGame(game_dados);
  } while (jogar_novamente());
}

int jogar_novamente(void) {
  printf("Você quer jogar novamente? [s/n]:  ");
  
  int c, op;
  while ((c = getc(stdin)) != EOF && c != '\n')
    op = c;
  if (c == EOF)
    return 0;
  if (op == 'S' || op == 's')
    return 1;
  return 0;
}
