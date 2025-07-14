#include "forca.h"
#include <stdlib.h>
#include <time.h>

void free_ForcaGame(struct ForcaGame *);

int main(int argc, char *argv[]) {
  srand(time(NULL));
  struct ForcaGame *game_data = forca_get_data(argc, argv);

  forca_start_game(game_data);

  return 0;
}

void free_ForcaGame(struct ForcaGame *game_data) {
  for (int i = 0; game_data->word_list != NULL; i++)
    free(game_data->word_list[i]);
  free(game_data->word_list);
  free(game_data->tip);
  free(game_data);
}
