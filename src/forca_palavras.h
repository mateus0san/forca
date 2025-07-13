#ifndef PALAVRAS_H
#define PALAVRAS_H


struct PalavraLista {
  char  **lista_palavras;
  char *nome_lista;
  int fallback; // a lista é um fallback? 1 ou 0
};

/*
   essa funcionalidade não é boa para acrescentar muitos arquivos,
   não acrescente muitos arquivos
*/
   
/* para adicionar mais palavras:
   crie um arquivo .c semelhante a programação.c no diretório root do projeto
   (não esqueça do NULL no último item e a função)
   exemplo: carros.c
   depois adicione em palavras.h, junto com as outras funções:
   struct PalavraLista palavras_carros_funcao();
   agora verifique o arquivo palavras.c
*/ 

// atualize o numero de palavras_funcoes caso adicione ou remova alguma
#define NUMERO_DE_FUNCOES 3
struct PalavraLista palavras_programacao_funcao();
struct PalavraLista palavras_animais_funcao();
struct PalavraLista palavras_tecnologia_funcao();

// função utilizada em forca_arquivo.c
struct PalavraLista palavras_retorne_lista_padrao();
// desaloca uma lista_palavras
void free_lista_palavras(struct PalavraLista *lista); 

#endif
