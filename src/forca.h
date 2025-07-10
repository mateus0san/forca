/* if FORCA_H (forca.h) não está definido, inclua (include) */
#ifndef FORCA_H
#define FORCA_H

/* declaração de dados para o jogo */

struct ForcaPalavra {
  char *dica;    // será equivalente a dica[];
  char *palavra; // será equivalente a palavra[];
  char *ad_palavra; // palavra para ser advinhada
};
struct ForcaGame {
  int numero_acertos;
  int numero_erros;
  struct ForcaPalavra palavra_dados;
};

/* fim da declaração de dados para o jogo */

/* declarações para forca_dados.c */

// retorna os dados para um novo jogo 
struct ForcaGame forca_dados_novo_jogo(int, const char *const *);

// desaloca os dados retornados por forca_dados_novo_jogo 
void free_ForcaGame(struct ForcaGame);

/* fim das declarações de forca_dados.c */

/* declarações para forca_jogar.c */

// forca_jogar deve receber um struct retornada por forca_dados_novo_jogo
// para começar o jogo
void forca_jogar(struct ForcaGame);

/* fim das declarações para forca_jogar.c */

#endif /* forca.h incluído */
