/* if FORCA_H (forca.h) não está definido, inclua (include) */
#ifndef FORCA_H
#define FORCA_H

/* declarações para forca_aquivo.h */

/* guarda informações da palavra
   apos usar essa struct com forca_arquivo_carregar_lista
   use free_ForcaGame */
struct ForcaPalavra {
  char *dica;    // será equivalente a dica[];
  char *palavra; // será equivalente a palavra[];
};
struct ForcaGame {
  int numero_acertos;
  int numero_erros;
  char caracteres_chutados[27]; // 26 letras do alfabeto + '\0' = 27
  struct ForcaPalavra palavra_dados;
};

struct ForcaGame forca_arquivo_dados_novogame(int, char **);
void free_ForcaGame(struct ForcaGame);

/* fim das declarações de forca_arquivo.h */

#endif /* forca.h incluído */
