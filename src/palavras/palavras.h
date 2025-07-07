// palavras.h é apenas incluído em forca_arquivo.c
#ifndef PALAVRAS_H
#define PALAVRAS_H

extern const char *palavras_programacao[];
extern const char *palavras_animais[];
#define PALAVRA_LISTA_NUMERO 2
/* para adicionar mais palavras:
   crie um arquivo .c semelhante a programação.c no diretório palavras/palavras_arquivos
   exemplo: palavras/palavras_arquivos/carros.c
   depois adicione em palavras.h, acima desse comentário, e depois do 'extern' o seguinte:
   extern const char *palavras_carros[];
   atualize o número de PALAVRA_LISTA_NUMERO
   depois adicione um return em palavras.c
*/ 

const char **palavras_retorne_lista_padrao();

#endif
