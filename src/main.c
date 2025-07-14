#include "forca.h"
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  srand(time(NULL));
  struct ForcaGame *game_data = forca_get_data(argc, argv);

  forca_start_game(game_data);

  free_ForcaGame(game_data);

  return 0;
}

