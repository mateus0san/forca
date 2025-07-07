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
Os commits contam a história do projeto. 3 vezez que o projeto começou do zero.

## Download com git
```bash
git clone https://github.com/mateus0san/forca.git
```

## Primeira vez compilando
Dentro do diretório forca, com CMake instalado, escolha uma das opções abaixo, Linux ou Windows
### cmake
Windows
```bat
build.bat
```
> **NOTA:** No Windows, com CMake instalando, a compilação pode ocorrer se você clicar no build.bat

Linux
```bash
./build.sh
```

> **ATENÇÃO:** Compilação usando IDEs depende da ferramenta, procure sobre a sua no google.

## Desenvolvedores
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
