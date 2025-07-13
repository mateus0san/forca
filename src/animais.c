#include "palavras.h"
#include <stdlib.h>
#include <string.h>


static char *animais = "animais";
const char *const palavras_animais[] = {
  "Gato",
  "Cachorro",
  "Cavalo",
  "Leao",
  "Tigre",
  "Elefante",
  "Girafa",
  "Jacare",
  "Onca",
  "Urso",
  "Tamandua",
  "Capivara",
  "Tatu",
  "Lobo",
  "Raposa",
  "Coruja",
  "Pato",
  "Ganso",
  "Galinha",
  "Galo",
  "Vaca",
  "Boi",
  "Porco",
  "Rato",
  "Camaleao",
  "Coelho",
  "Golfinho",
  "Baleia",
  "Tubarao",
  "Pinguim",
  "Foca",
  "Cavalo marinho",
  "Polvo",
  "Lula",
  "Arraia",
  "Jacare",
  "Cobra",
  "Sapo",
  "Perereca",
  "Libelula",
  "Borboleta",
  "Abelha",
  "Formiga",
  "Grilo",
  "Besouro",
  "Mosquito",
  "Cavalo",
  "Anta",
  "Arraia",
  "Morcego",
  NULL
};

struct PalavraLista palavras_animais_funcao() {
  struct PalavraLista lista;

  lista.lista_palavras = palavras_animais;
  lista.nome_lista = malloc(strlen(animais) + 1);
  lista.fallback = 1;
  strcpy(lista.nome_lista, animais);
  return lista;
}
