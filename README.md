# Forca

## PROGRAMAÇÃO II
O objetivo é revisar os assuntos lecionados na disciplina(PROGII) de
uma maneira coesa e organizada. O código terá mais comentários do
que deveria em um código real, para facilitar o aprendizado e busca de
informação.

## Commits
O histórico de commits é importante para entendermos a evolução do projeto.
Os commits deverão fazer uma coisa só ou de uma maneira muita organizada
que faça sentido. Exemplos:
```bash
git commit -m 'Comentando a função foobar()'
git commit -m 'Adicionando um subrotina para tratar a variável foo'
git commit -m 'Removendo parâmetro que não é utilizado'
git commit -m 'Refatorando a função soma'
```
Um commit específico, que faz uma coisa. As coisas começam a ficar bagunçadas
se um commit faz muitas mudanças. Isso também se aplica a projetos reais!!!

## História do projeto
O projeto foi reiniciado do zero 3 vezes. Isso reflete o processo real de desenvolvimento: errar, recomeçar, refatorar. Os commits contam essa história.

## Download com git
```bash
git clone https://github.com/mateus0san/forca.git
```

## Primeira vez compilando
Dentro do diretório forca, com CMake instalado e configurado, escolha uma das opções abaixo, Linux ou Windows
### cmake
Windows
```bat
build.bat
```
> **NOTA:** No Windows, com CMake instalando e configurado, a compilação pode ocorrer se você clicar no build.bat

Linux
```bash
./build.sh
```
### GCC
Muito ruim compilar assim...
```c
gcc main.c forca_arquivo.c forca_desenha.c palavras/palavras.c palavras/palavras_arquivos/animais.c palavras/palavras_arquivos/programacao.c palavras/palavras_arquivos/tecnologia.c
```
> **ATENÇÃO:** Compilação usando IDEs depende da ferramenta, procure sobre a sua no google.

## Desenvolvedores recompilando usando cmake ou compilando pela primeira vez
Para recompilar os binários, dentro do diretório build rode: 
```bash
cmake --build .
```
Para atualizar as configurações de build após modificar algo em CMakeLists.txt, dentro do
diretório build rode:
```bash
cmake ..
```
> **ATENÇÃO:** Novamente, recompilar usando uma IDE depende da ferramenta, e provavelmente o
>  processo é igual a compilar.

## Executando
Após compilar o binário, dentro do diretório build/, para executar rode:

Linux
```bash
./forca
```

Windows
```bash
.\forca
```
> **Nota:** Clicar no binário talvez o execute.

## source code tree
```text
forca/
├── src/
│   ├── main.c
│   ├── forca_arquivo.c  responsável por lidar com arquivos
│   ├── forca_desenha.c  responsável por desenhar no output
│   ├── palavras.c       define o que é uma lista de palavras
│   ├── forca_string.h   verifica strings para que estajam no padrão pro jogo
│   ├── windows_linux.c  define funções compátivies com o sistema
│   ├── animais.c        arquivo de fallback (caso o usuário não forneça palavras pro jogo)
│   ├── programacao.c    arquivo de fallback
│   └── tecnologia.c     arquivo de fallback
│   └── lib/ bibliotecas, (possuem a declaração de funções e structs públicas)
│       ├── forca.h
│       ├── forca_arquivo.h
│       ├── forca_desenho.h
│       ├── palavras.h
│       ├── windows_linux.h
```
