/* forca_arquivo.c lida com a logica necessária para lidar com arquivos */
//
// 
//
//
//
/* lista de palavras, caso nenhum banco de palavras seja informado (arquivo)
   use a lista de palavras

   Isso é um array de ponteiros, possuem propriedades interessantes, como por
   exemplo, perceba que as strings possuem tamanhos diferentes, em um array
   fixo, PROGRAMACAO[10][10], você teria 10 strings com 10 posições, uma
   string como "python", não usaria as 10 posições, já com array de ponteiros
   a string gcc só ocupa 3 posições +1 com o '\0'(nulo no final da string)
*/
const char *PROGRAMACAO[] = {
  "gcc",
  "git",
  "github",
  "python",
  "rust",
  "programacao orientada a objetos",
  "" // string vazia para idicar fim da lista
};
