#include <stdlib.h>
#include "lib/windows_linux.h"


void clear_screen(void) {
  #ifdef _WIN32
      system("cls");
  #else
      system("clear");
  #endif
}

void system_pause(void) {
    #ifdef _WIN32
      system("pause");
    #else
      system("read -n1 -r -p 'Pressione alguma tecla para continuar\n' key_lixo_forca");
    #endif
}
