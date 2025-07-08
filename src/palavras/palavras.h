// palavras.h é apenas incluído em forca_arquivo.c
#ifndef PALAVRAS_H
#define PALAVRAS_H

/*
   essa funcionalidade não é boa para acrescentar muitos arquivos,
   não acrescente muitos arquivos
*/
   
/* para adicionar mais palavras:
   crie um arquivo .c semelhante a programação.c no diretório palavras/palavras_arquivos
   (não esqueça da string vazia no último item e a função)
   exemplo: palavras/palavras_arquivos/carros.c
   depois adicione em palavras.h, junto com as outras funções:
   const char *const *carros();
   agora verifique o arquivo palavras.c
*/ 

// atualize o numero de palavras_funcoes caso adicione ou remova alguma
#define NUMERO_DE_FUNCOES 2
const char *const *palavras_programacao_funcao();
const char *const *palavras_animais_funcao();

// função utilizada em forca_arquivo.c
const char *const *palavras_retorne_lista_padrao();

#endif
