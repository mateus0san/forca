#ifndef FORCA_DESENHE_H
#define FORCA_DESENHE_H

#include "forca.h"

struct ForcaDesenha {
  char *palavra_desconhecida;
  char chutes[27]; // alfabeto + '\0' == 26 + 1
  char *dica;
  int erros;
};

void forca_desenha(struct ForcaDesenha);

struct ForcaDesenha forca_desenha_new_ForcaDesenha(struct ForcaGame);

struct ForcaDesenha forca_desenha_free_ForcaDesenha(struct ForcaDesenha);

#endif
