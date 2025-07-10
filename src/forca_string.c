#include <ctype.h>
#include <stdio.h>

static void char_invalido(int c);
static void print_strings_validas(void);

int forca_stdin_ler_string(char *buf, int max_buf) {
  int c;
  int i = 0;
  while ((c = getc(stdin)) != EOF && c != '\n' && i < max_buf) {
    if (!isalpha(c) && !isspace(c)) {
      char_invalido(c);
      i = 0;
      break;
    }
    buf[i++] = c; 
  }

  buf[i] = '\0';

  if (c == EOF)
    return 0;

  
  return i;
}


static void char_invalido(int c) {
  fprintf(stderr, "Forca -> char inválido: %c\n", c);
  print_strings_validas();
}

static void print_strings_validas(void) {
  fprintf(stderr, "Forca -> strings válidas: 'python', 'prato feito'...\n");
}
