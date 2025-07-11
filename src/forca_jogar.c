#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "lib/forca.h"
#include "lib/forca_desenha.h"
#include "lib/forca_string.h"

#define MAX_CHUTE 50
struct Chutes {
  char string[MAX_CHUTE];
  int len;
};

static int caractere_chute(char *, struct Chutes, struct ForcaDesenha);
static int palavra_chute(char *, struct Chutes, struct ForcaDesenha);
static int lidar_chute(char *, struct ForcaDesenha, struct Chutes);
static void loop(struct ForcaGame, struct ForcaDesenha);

void forca_jogar(struct ForcaGame game_dados) {

  struct ForcaDesenha desenha_dados= forca_desenha_new_ForcaDesenha(game_dados);

  // se não é valida, return
  if (forca_string_valida(game_dados.palavra, desenha_dados.dica))
    return;
  loop(game_dados, desenha_dados);
}

static void loop(struct ForcaGame dados, struct ForcaDesenha desenha) {
  struct Chutes chute;
  do {
    forca_desenha(desenha);
    chute.len = forca_string_ler(chute.string, MAX_CHUTE);
  } while ((chute.len == EOF) ? 0 : lidar_chute(dados.palavra, desenha, chute));
}

static int lidar_chute(char *palavra, struct ForcaDesenha desenha, struct Chutes chute) {
  if (chute.len > 1)
      return palavra_chute(palavra, chute, desenha);
  else if (chute.len == 1)
      return caractere_chute(palavra, chute, desenha);
  else
      return 1;
}

#define NUMERO_ERROS 6
static int palavra_chute(char *palavra, struct Chutes chute, struct ForcaDesenha desenha) {
  if (strcmp(chute.string, palavra) == 0) {
    forca_desenhe_venceu(palavra);
    return 0;
  } else if ((*desenha.erros += chute.len) >= NUMERO_ERROS) {
    forca_desenhe_perdeu(palavra);
    return 0;
  }
  return 1;
}

static int caractere_chute(char *palavra, struct Chutes chute, struct ForcaDesenha desenha) {
  int count = 0;
  for (int i = 0; palavra[i] != '\0'; i++) {
    if (chute.string[0] != palavra[i])
      continue;
    desenha.palavra_desconhecida[i] = chute.string[0];
    count++;
  }

  if (count == 0) {
    *desenha.erros += 1;
  }
  if (*desenha.erros >= NUMERO_ERROS) {
    forca_desenhe_perdeu(palavra);
    return 0;
  }
  
  return 1;
}

