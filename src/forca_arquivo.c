/* forca_aquivo.c deve lidar com arquivos relacionados ao
   jogo e em caso de erro, chamar fallback para usar uma
   lista de palavras padrão, definida em palavras/palavras.h.
   forca_arquivo.c deve retornar uma struct PalavraLista

   forca_arquivo.c deve retornar uma lista de palavras, será
   nessário refatoração.
*/ 


#include "lib/palavras.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lib/windows_linux.h"

/* funções declaradas com static estão limitadas ao seu escopo,
  no caso, carregar_fallback() está limitada a
  forca_arquivo.c, mais nenhum outro arquivo pode usar esse
  função, aqui começamos a ver como nasce o conceito de
  public e private do java, o pub do rust, e outras linguagens.
*/

static struct PalavraLista carregar_fallback(void);
static int carregar_lista(const char *const, struct PalavraLista *);
static int arg_linha(int, const char * const *, struct PalavraLista *);
static int ler_arquivo(FILE *, struct PalavraLista *); 
static int conta_palavras(FILE *arquivo);

static int ARGS = 1;
struct PalavraLista forca_arquivo_retorne_lista_palavra(int argc, const char * const argv[]) {
  struct PalavraLista lista;

  if (ARGS != 0 && arg_linha(argc, argv, &lista) == 1)
    return lista;
  /* fazer mais tarde
    lógica para o usuário digitar nome de arquivos, por hora
    considerar que o usuário não forneceu arquivos válidos
  */

  /* fazer mais tarde
    lógica para usuário digitar palavras para seu jogo, por hora
    considerar que o usuário não quer digitar palavras
  */
    
  /* considerando que os casos anteriores não deram certo
    precisamos ter uma fallback */  

  return carregar_fallback();
}

static struct PalavraLista carregar_fallback() {

  // struct em palavras.h
  struct PalavraLista lista = palavras_retorne_lista_padrao();

  return lista;
}

static int arg_linha(int argc, const char * const argv[], struct PalavraLista *lista) {
    if (argc-- == 1) {
      fprintf(stderr, "Forca -> não informado argumentos na linha de comando...\n");
      system_pause();
      ARGS = 0;
      return 0;
    }
    int i = rand() % argc + 1;

    return carregar_lista(argv[i], lista);
}

static int carregar_lista(const char *const file_name, struct PalavraLista *lista) {
  FILE *arquivo = fopen(file_name, "r");

  if (arquivo == NULL) {
    fprintf(stderr, "Forca -> não foi possível ler o arquivo %s\n", file_name);
    system_pause();
    ARGS = 0;
    return 0;
  }

  lista->nome_lista = malloc(strlen(file_name) + 1);
  strcpy(lista->nome_lista, file_name);
  lista->fallback = 0;

  return ler_arquivo(arquivo, lista);
}

static int ler_arquivo(FILE *arquivo, struct PalavraLista *lista) {

  int cont_palavras = conta_palavras(arquivo);

  char **palavras = malloc((cont_palavras + 1) * sizeof(char *));
  size_t size = 0;
  int i;

  for (i = 0; i < cont_palavras; i++) {
    palavras[i] = NULL;
    if (getline(&(palavras[i]), &size, arquivo) == -1) {
      free(palavras[i]);
      break;
    }
  }

  palavras[i] = NULL;

  lista->lista_palavras = (const char *const *) palavras;

  return 1;
}

static int conta_palavras(FILE *arquivo) {
  int palavra_count = 0;
  int c; 

  while ((c = getc(arquivo)) != EOF) {
    if (c == '\n')
      palavra_count++;
  }

  rewind(arquivo);
  return palavra_count;
}
