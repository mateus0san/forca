/* forca_aquivo.c deve lidar com arquivos relacionados ao
   jogo e em caso de erro, chamar fallback para usar uma
   lista de palavras padrão, definida em palavras/palavras.h
*/ 
#include "palavras/palavras.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "forca.h"


/* funções declaradas com static estão limitadas ao seu escopo,
  no caso, forca_arquivo_carregar_fallback() está limitada a
  forca_arquivo.c, mais nenhum outro arquivo pode usar esse
  função, aqui começamos a ver como nasce o conceito de
  public e private do java, o pub do rust, e outras linguagens.
*/

static struct ForcaGame forca_arquivo_carregar_fallback(struct ForcaGame game_dados) {

  struct PalavraLista lista = palavras_retorne_lista_padrao();

  // inicializando a struct e imprimindo para casos de teste
  game_dados.palavra_dados.dica = lista.nome_lista;
  game_dados.palavra_dados.palavra = malloc(strlen(lista.lista_palavras[0]));
  strcpy(game_dados.palavra_dados.palavra, lista.lista_palavras[0]);
  game_dados.numero_acertos = 0;
  game_dados.numero_errors = 0;

  printf("palavra_dados.palavra: %s\n", game_dados.palavra_dados.palavra);
  printf("palavra_dados.dica: %s\n", game_dados.palavra_dados.dica);
  printf("ForcaGame.numero_acertos: %d\n", game_dados.numero_acertos);
  printf("ForcaGame.numero_erros: %d\n", game_dados.numero_errors);

  return game_dados;
}

struct ForcaGame forca_arquivo_carregar_lista(int argc, char *argv[]) {
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

  struct ForcaGame game_dados;
  return forca_arquivo_carregar_fallback(game_dados);
}
