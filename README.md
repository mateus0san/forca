# Forca

## Source code
O código consiste na `main.c`, `forca.h` e `forca.c`.
O arquivo main.c é bem descritivo, um loop onde selecionamos
um arquivo aleatoriamente, depois aleatoriamente, selecionamos
um palavra do arquivo, e por fim, começamos o jogo usando o
nome do arquivo e a palavra selecionada.

## Usabilidade
O programa deve receber nome de arquivos como parâmetros,
arquivos que devem possuir no máximo 50 palavras e preferencialmente
o nome do arquivo deve estar relacionado com as palavras, o nome do
arquivo serve como dica para adivinhar a palavra.

O usuário pode digitar letras de A-Za-z ou palavras como `python` ou
`rust programming language`, erros serão reletados caso 
o usurário informe palavras fora desse padrão.

### Executando e compilando
```bash
gcc main.c forca.c
./a.out file1 file2 ...
```
