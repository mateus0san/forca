/**
 * @file forca_system.c
 * @brief define funções compatíveis de mais baixo nível do Linux e Windows
*/
#include <stdio.h>
#include "forca_system.h"

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

void *system_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    fprintf(stderr, "forca: malloc error\n");
    exit(1);
  }

  return ptr;
}
