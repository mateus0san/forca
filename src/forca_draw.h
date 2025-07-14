#ifndef FORCA_DRAWN_H
#define FORCA_DRAWN_H

struct Draw {
  char *unknown_word;
  char guesses[257]; // ascii table
  char *tip;
  int errors; 
};

void forca_draw(struct Draw *);
void forca_draw_won(char *word); 
void forca_draw_lost(char *); 

#endif
