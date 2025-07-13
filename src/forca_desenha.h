#ifndef FORCA_DESENHE_H
#define FORCA_DESENHE_H

#include "forca.h"

struct ForcaDesenha {
  char *palavra_desconhecida;
  char *dica;
  char chutes[27]; // alfabeto + '\0' == 26 + 1
  int erros;
};

void forca_desenha(struct ForcaDesenha *);
void forca_desenhe_venceu(char *);
void forca_desenhe_perdeu(char *);

struct ForcaDesenha *forca_desenha_new_ForcaDesenha(struct ForcaGame);

void forca_desenha_free_ForcaDesenha(struct ForcaDesenha *);

#endif
