#include <stdio.h>
#include <string.h>

/* lista de palavras, caso nenhum banco de palavras seja informado (arquivo)
   use a lista de palavras
*/
/* a lista será movido para um arquivo .h */
const char *programacao[] = {
  "gcc",
  "git",
  "github",
  "python",
  "rust",
  "programacao orientada a objetos",
  ""
};

int main(void) {
  
  // test para a lista de palavras programacao, isso será removido
  for (int i = 0; strcmp(programacao[i], "") != 0; i++) {
    printf("%s\n", programacao[i]);
  }
}
