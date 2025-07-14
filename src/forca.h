#ifndef FORCA_H
#define FORCA_H

struct ForcaGame {
  char **word_list;
  char *tip;
  int n_words;
};

struct ForcaGame *forca_get_data(int, char **);

void forca_start_game(struct ForcaGame *);

void free_ForcaGame(struct ForcaGame *);

#endif
