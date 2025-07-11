#include <ctype.h>
#include <stdio.h>
#include "lib/windows_linux.h"

static int char_invalido(int);
static void palavra_invalida(char *, char *);
static void print_strings_validas(void);

int forca_string_ler(char *buf, int max_buf) {
  int c;
  int i = 0;

  printf("Digite uma letra ou a palavra: ");
  while ((c = getc(stdin)) != EOF && c != '\n' && i < max_buf) {
    if (char_invalido(c)) {
      // limpar buffer do teclado, ma32teus:
      // quando chegar no 32 dará char invalido e lipará a string
      // lendo ela toda
      while ((c = getc(stdin)) != EOF && c != '\n');
      i = 0;
      break;
    }
    buf[i++] = tolower(c); 
  }

  buf[i] = '\0';

  if (c == EOF)
    return c;
  
  return i;
}

int forca_string_valida(char *palavra, char *dica) {
  int i;
  for (i = 0; palavra[i] != '\0'; i++) {
    if (char_invalido(palavra[i])) {
      palavra_invalida(palavra, dica);
      return 1;
    }
    palavra[i] = tolower(palavra[i]);
  }

  return  0;
}

static void palavra_invalida(char *palavra, char *dica)  {
  fprintf(stderr, "Forca -> palavra inválida(%s) em: (%s)", palavra, dica);
  system_pause();
}


static int char_invalido(int c) {
  if (!isalpha(c) && !isspace(c)) {
    fprintf(stderr, "Forca -> char inválido: %c\n", c);
    print_strings_validas();
    return 1;
  }
  return 0;
}

static void print_strings_validas(void) {
  fprintf(stderr, "Forca -> strings válidas: 'python', 'prato feito'...\n");
  system_pause();
}
