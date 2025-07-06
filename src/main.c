#include <stdio.h>
#include <string.h>

/* lista de palavras, caso nenhum banco de palavras seja informado (arquivo)
   use a lista de palavras

   Isso é um array de ponteiros, possuem propriedades interessantes, como por
   exemplo, perceba que as strings possuem tamanhos diferentes, em um array
   fixo, PROGRAMACAO[10][10], você teria 10 strings com 10 posições, uma
   string como "python", não usária as 10 posições
*/

const char *PROGRAMACAO[] = {
// a lista será movido para um arquivo .h futuramente 
  "gcc",
  "git",
  "github",
  "python",
  "rust",
  "programacao orientada a objetos",
  ""
};

int main(void) {
  
  // test para a lista de palavras PROGRAMACAO, isso será removido
  for (int i = 0; strcmp(PROGRAMACAO[i], "") != 0; i++) {
    printf("%s\n", PROGRAMACAO[i]);
  }
}
