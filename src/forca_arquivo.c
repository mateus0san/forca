/* forca_aquivo.c deve lidar com arquivos relacionados ao
   jogo e em caso de erro, chamar fallback para usar uma
   lista de palavras padrão, definida em palavras/palavras.h
*/ 
#include "palavras/palavras.h"
#include "forca.h"

/* funções declaradas com static estão limitadas ao seu escopo,
  no caso, forca_arquivo_carregar_fallback() está limitada a
  forca_arquivo.c, mais nenhum outro arquivo pode usar esse
  função, aqui começamos a ver como nasce o conceito de
  public e private do java, o pub do rust, e outras linguagens.
*/
static const char *const *forca_arquivo_carregar_fallback() {
  return palavras_retorne_lista_padrao();
}

const char *const *forca_arquivo_carregar_lista(int argc, char *argv[]) {
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
  return forca_arquivo_carregar_fallback();
}
