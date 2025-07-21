#include <stdio.h>
#include "system_compatible.h"
#include <string.h>

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

#define MAX_LINE 1000
char *my_getline(FILE *file) {
  char line[MAX_LINE];
  int i = 0;
  int c;
  while ((c = getc(file)) != EOF && c != '\n' && i < MAX_LINE) {
    line[i++] = c;
  }

  if (c == EOF && file == stdin)
      exit(1);
  
  line[i] = '\0';
  int len_line = strlen(line);

  if (len_line < 1)
    return NULL;

  char *p = system_malloc(strlen(line) + 1);
  strcpy(p, line);

  return p; 
}
