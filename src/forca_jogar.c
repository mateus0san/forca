#include "lib/forca_desenha.h"

static struct ForcaDesenhe new_FocaDesenhe(struct ForcaGame);

void forca_jogar(struct ForcaGame game_dados) {

  struct ForcaDesenha desenha_dados= forca_desenha_new_ForcaDesenha(game_dados);

  forca_desenha(desenha_dados);
}
