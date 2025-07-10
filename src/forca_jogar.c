#include "lib/forca_desenha.h"
#include "lib/forca_string.h"
#include <stdio.h>

#define MAX_CHUTE 50

static struct ForcaDesenhe new_FocaDesenhe(struct ForcaGame);
void forca_jogar(struct ForcaGame game_dados) {

  struct ForcaDesenha desenha_dados= forca_desenha_new_ForcaDesenha(game_dados);

  forca_desenha(desenha_dados);

  char usuario_chute[MAX_CHUTE];

  forca_stdin_ler_string(usuario_chute, MAX_CHUTE);

  printf("%s:::", usuario_chute);
}
