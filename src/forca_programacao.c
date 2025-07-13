/* lista de palavras, caso nenhum banco de palavras seja informado (arquivo)
   use a lista de palavras

   Isso é um array de ponteiros, possuem propriedades interessantes, como por
   exemplo, perceba que as strings possuem tamanhos diferentes, em um array
   fixo, PROGRAMACAO[10][10], você teria 10 strings com 10 posições, uma
   string como "python", não usaria as 10 posições, já com array de ponteiros
   a string 'gcc' só ocupa 3 posições +1 com o '\0'(nulo no final da string)
*/

#include "forca_palavras.h"
#include <stdlib.h>
#include <string.h>

char *palavras_programacao[] = {
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
  lista.fallback = 1;
  strcpy(lista.nome_lista, programacao);
  return lista;
}
