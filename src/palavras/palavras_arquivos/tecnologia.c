#include "../palavras.h"
#include <stdlib.h>
#include <string.h>

static char *tecnologia = "tecnologia";
const char *const palavras_tecnologia[] = {
  "Smartphone",
  "Computador",
  "Laptop",
  "Tablet",
  "Televisao",
  "Radio",
  "Fone de ouvido",
  "Caixa de som",
  "Smartwatch",
  "Relogio inteligente",
  "Drone",
  "Impressora",
  "Webcam",
  "Modem",
  "Roteador",
  "Receptor",
  "Microfone",
  "Projetor",
  "Console de videogame",
  "Controle remoto",
  "GPS",
  "Camera digital",
  "Maquina fotografica",
  "Video game",
  "Console",
  "Aparelho de Blu ray",
  "DVD player",
  "Gravador de voz",
  "Calculadora",
  "Ar condicionado",
  "Ventilador",
  "Aquecedor",
  "Microondas",
  "Geladeira",
  "Fogao",
  "Lava loucas",
  "Maquina de lavar",
  "Ferro de passar",
  "Aspirador de po",
  "Camera de seguranca",
  "Router",
  "Tablet de desenho",
  "Termometro digital",
  "Lampada inteligente",
  "Power bank",
  "Carregador",
  "Dispositivo de streaming",
  "Leitor de cartao",
  "Smart TV",
  "Chromecast",
  NULL
};


struct PalavraLista palavras_tecnologia_funcao() {
  struct PalavraLista lista;

  lista.lista_palavras = palavras_tecnologia;
  lista.nome_lista = malloc(strlen(tecnologia) + 1);
  strcpy(lista.nome_lista, tecnologia);
  return lista;
}
