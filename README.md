# Forca

## PROGRAMAÇÃO II
O objetivo é revisar os assuntos lecionados na disciplina de
uma maneira coesa e organizada.

# Download
```bash
git clone https://github.com/mateus0san/forca.git
```

# Compilando
Compilaçãcao dependente de IDE não será documentada, seria extremamente
casativo demostrar todos os casos (CodeBlocks, Vscode, Visual Studio...)

Todos os comandos a seguir devem ser rodados dentro do diretório do projeto.
## Compilando com cmake
Caso possua o cmake instalado e configurado, no diretório do projeto rode:
```bash
mkdir build
cd build
cmake
```

## Compilando  com GCC
Caso seu shell aceite 'wildcard expansion'
```bash
gcc *.c
```
Caso seu shell não aceite 'wildcard expansion'
```bash
gcc forca_data.c  forca_draw.c  forca_draw.h  forca_game.c  forca.h\
forca_system.c  forca_system.h  main.c
```

# Executando
A lista de palavras aceita no programa segue esse padrão
```text
javascript
python
rust
java virtual machine
```
## Executando: Método 1
O programa aceita um arquivo como argumento, esse arquivo deve ser uma lista de
palavras
```bash
./forca arq
```

## Executando: Método 2
Caso não seja informado nenhum argumento na inicialização do programa, o
usuário deverá informar o nome do arquivo em execução.
```bash
Enter the file name: arq
```

# source code tree
```text
forca/
├── src/
│   ├── main.c
│   ├── forca_data.c     responsável por lidar com arquivos
│   ├── forca_game.c     responsável por lidar com a lógica do jogo
│   ├── forca_data.c     responsável por lidar com arquivos
│   ├── forca_draw.h     responsável por desenhar no output 
│   ├── forca_system.c   define funções compátivies com o sistema
│ bibliotecas, (possuem a declaração de funções e structs públicas)
│   ├── forca.h
│   ├── forca_draw.h
│   ├── forca_system.h
│   └── windows_linux.h
```
