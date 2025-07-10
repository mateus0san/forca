/* lista de palavras, caso nenhum banco de palavras seja informado (arquivo)
   use a lista de palavras

   Isso é um array de ponteiros, possuem propriedades interessantes, como por
   exemplo, perceba que as strings possuem tamanhos diferentes, em um array
   fixo, PROGRAMACAO[10][10], você teria 10 strings com 10 posições, uma
   string como "python", não usaria as 10 posições, já com array de ponteiros
   a string 'gcc' só ocupa 3 posições +1 com o '\0'(nulo no final da string)
*/

/*
  'recursive descent parser', uma boa pros estudos, mas não pros padrões da disciplina
  de progII, entenda que isso é apenas um array de ponteiros.

  C usa um 'recursive descent parser' para analisar suas declarações.
  
  pode ignorar esse campo de comentário se quiser
  
  palavras_programacao[]           -> é um array de...

   * const                         -> é um array de ponteiros constantes para...

   const char                      -> é um array de ponteiros constantes para caracteres constantes

   const char * const palavras_programacao[];
   => palavras_programacao é um array de ponteiros constantes para char constantes
*/
   
#include "lib/palavras.h"
#include <stdlib.h>
#include <string.h>

const char *const palavras_programacao[] = {
  "Algoritmo",
  "Codigo",
  "Variavel",
  "Funcao",
  "Loop",
  "Condicional",
  "Classe",
  "Objeto",
  "Metodo",
  "Interface",
  "Heranca",
  "Polimorfismo",
  "Abstracao",
  "Encapsulamento",
  "Framework",
  "Biblioteca",
  "Repositorio",
  "Branch",
  "Commit",
  "Merge",
  "Pull request",
  "Push",
  "Teste",
  "Debug",
  "IDE",
  "Editor de texto",
  "Compilador",
  "Interpretador",
  "Linguagem",
  "Python",
  "Java",
  "C",
  "Ruby",
  "JavaScript",
  "HTML",
  "CSS",
  "SQL",
  "API",
  "REST",
  "Endpoint",
  "Microservico",
  "Server",
  "Frontend",
  "Backend",
  "Banco de dados",
  "Arquitetura",
  "MVC",
  "Git",
  "Nodejs",
  "Docker",
  NULL // null para idicar fim da lista
};

struct PalavraLista palavras_programacao_funcao() {
  struct PalavraLista lista;
  char *programacao = "programacao";

  lista.lista_palavras = palavras_programacao;
  lista.nome_lista = malloc(strlen(programacao) + 1);
  strcpy(lista.nome_lista, programacao);
  return lista;
}
