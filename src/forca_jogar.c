#include <string.h>
#include <stdio.h>
#include "windows_linux.h"
#include "forca.h"
#include "forca_desenha.h"
#include "forca_string.h"

#define MAX_CHUTE 50
struct Chutes {
  char string[MAX_CHUTE];
  int len;
};

static int venceu_perdeu(char *, struct Chutes, struct ForcaDesenha *);
static int ja_chutou_char(char *, char);
static void caractere_chute(char *, struct Chutes, struct ForcaDesenha *);
static void palavra_chute(char *, struct Chutes, struct ForcaDesenha *);
static int lidar_chute(char *, struct ForcaDesenha *, struct Chutes);
static void loop(struct ForcaGame, struct ForcaDesenha *);

void forca_jogar(struct ForcaGame game_dados) {


  // se não é valida, return
  if (forca_string_valida(game_dados.palavra, game_dados.dica))
    return;

  struct ForcaDesenha *desenha_dados = forca_desenha_new_ForcaDesenha(game_dados);

  loop(game_dados, desenha_dados);
}

static void loop(struct ForcaGame dados, struct ForcaDesenha *desenha) {
  struct Chutes chute;
  do {
    forca_desenha(desenha);
    chute.len = forca_string_ler(chute.string, MAX_CHUTE);
  } while ((chute.len == EOF) ? 0 : lidar_chute(dados.palavra, desenha, chute));
}

static int lidar_chute(char *palavra, struct ForcaDesenha *desenha, struct Chutes chute) {
  if (chute.len > 1)
      palavra_chute(palavra, chute, desenha);
  else if (chute.len == 1)
      caractere_chute(palavra, chute, desenha);
  else
      return 1;
  
  return venceu_perdeu(palavra, chute, desenha);
}

#define NUMERO_ERROS 6
static void palavra_chute(char *palavra, struct Chutes chute, struct ForcaDesenha *desenha) {
  if (strcmp(chute.string, palavra) == 0)
    return;
  else 
    desenha->erros += chute.len;
}

static void caractere_chute(char *palavra, struct Chutes chute, struct ForcaDesenha *desenha) {
  if (ja_chutou_char(desenha->chutes, chute.string[0])) {
    return;
  }
  int count = 0;
  for (int i = 0; palavra[i] != '\0'; i++) {
    if (chute.string[0] != palavra[i])
      continue;
    desenha->palavra_desconhecida[i] = chute.string[0];
    count++;
  }

  if (count == 0) 
    desenha->erros += 1;
}

static int ja_chutou_char(char *lista_alfabeto, char c) {
  if (strchr(lista_alfabeto, c) != NULL) {
    printf("Você já chutou o char: %c\n", c);
    system_pause();
    return 1;
  }
  int i = 0;
  while (lista_alfabeto[i] != '\0')
    i++;
  lista_alfabeto[i++] = c;
  lista_alfabeto[i] = '\0';
  return 0;
}

static int venceu_perdeu(char *palavra, struct Chutes chute, struct ForcaDesenha *desenha) {
  if ((strcmp(palavra, desenha->palavra_desconhecida) == 0) || (strcmp(palavra, chute.string) == 0)) {
    forca_desenhe_venceu(palavra);
    return 0;
  } else if (desenha->erros >= NUMERO_ERROS) {
    forca_desenhe_perdeu(palavra);
    return 0;
  }

  return 1;
}
