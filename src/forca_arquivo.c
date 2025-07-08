/* forca_aquivo.c deve lidar com arquivos relacionados ao
   jogo e em caso de erro, chamar fallback para usar uma
   lista de palavras padrão, definida em palavras/palavras.h
*/ 
#include "palavras/palavras.h"
#include <string.h>
#include <stdlib.h>
#include "forca.h"


/* funções declaradas com static estão limitadas ao seu escopo,
  no caso, carregar_fallback() está limitada a
  forca_arquivo.c, mais nenhum outro arquivo pode usar esse
  função, aqui começamos a ver como nasce o conceito de
  public e private do java, o pub do rust, e outras linguagens.
*/

static char *escolher_palavra_lista(const char *const *); // dado uma lista de palavras, escolhe uma aleatoriamente
static struct ForcaGame new_ForcaGame(struct ForcaGame, struct PalavraLista);
static struct ForcaGame carregar_fallback(void);

struct ForcaGame forca_arquivo_dados_novogame(int argc, char *argv[]) {
  /* fazer mais tarde
    lógica para lidar com argc e argv, por hora considerar que
    o usuário não fornece argumentos pela linha de comando
  */

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


static struct ForcaGame carregar_fallback() {

  // struct em palavras.h
  struct PalavraLista lista = palavras_retorne_lista_padrao();
  // struct em forca.h
  struct ForcaGame game_dados;

  /* inicializando a struct
     um comportamento semelhante a inicialização
     de objetos(Programação orientada a objetos)
     em uma função definada em um escopo privado (static).
     game_dados seria o self :) */
  return new_ForcaGame(game_dados, lista);
}

static struct ForcaGame new_ForcaGame(struct ForcaGame game_dados, struct PalavraLista lista_palavras) {
   game_dados.palavra_dados.palavra = escolher_palavra_lista(lista_palavras.lista_palavras);
   game_dados.palavra_dados.dica = lista_palavras.nome_lista;
   game_dados.caracteres_chutados[0] = '\0';
   game_dados.numero_acertos = game_dados.numero_erros = 0;

  return game_dados;
}

void free_ForcaGame(struct ForcaGame game_dados) {
  free(game_dados.palavra_dados.palavra);
  free(game_dados.palavra_dados.dica);  
}

static char *escolher_palavra_lista(const char *const lista_palavras[]) {
  int count = 0; // quantas palavras há na lista

  /* a definição de lista de palavras aqui foi definida no
     palavras.h/programacao.c, onde no final da lista a um NULL */
  while (lista_palavras[count] != NULL) {
    count++;
  }

  unsigned index = rand() % count;

  char *palavra = malloc(strlen(lista_palavras[index]) + 1);
  strcpy(palavra, lista_palavras[index]);

  return palavra;
}
