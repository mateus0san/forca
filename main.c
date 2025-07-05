#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>

#define MAX_WORDS 50
#define MAX_WORD_SIZE 50

char *get_file(int, char **);
char *get_word(const char *);
void start_game(const char *, const char *);
int play_again(void);


//Wallace gabriel comentou aqui
//Ryan comentou aqui, inclusão da biblioteca locale.h

int main(int argc, char *argv[]) {
  srand(time(NULL));

  setlocale(LC_ALL, "Portuguese");

  char *file_name, *word;

  do {
    if ((file_name = get_file(argc, argv)) == NULL) {
      exit(EXIT_FAILURE);
    }

    if ((word = get_word(file_name)) == NULL) {
      exit(EXIT_FAILURE);
    }

      system("clear");
      start_game(file_name, word);
      free(word);
  } while (play_again());  
}

// funcao pergunta se voce quer jogar de novo
int play_again() {
  int c, op;
  printf("Voce quer jogar novamente? <s/n> ");
  while ((c = getc(stdin)) != EOF && c != '\n') {
    op = c;
  } 

  return ((op == 'S' || op == 's') && c == '\n') ? 1 : 0;
}
// return one string in argv
char *get_file(int argc, char *argv[]) {
  if (--argc < 1) {
    fprintf(stderr, "Forca: bad usage\n");
    return NULL;
  }

  int index = (rand() % argc) + 1;
  int len = strlen(argv[index]);

  if (len >= 50 || len == 0) {
    fprintf(stderr, "Forca: invalid argument: %s\n", argv[index]);
    return NULL;
  }

  return argv[index];
}

// read all words in a file
int read_words(FILE *fi, char **words) {
  int word_counter = 0;

  for (int i = 0; i < MAX_WORDS; i++) {
    if ((words[i] = malloc(MAX_WORD_SIZE)) == NULL) {
      fprintf(stderr, "Forca: malloc error\n");
      return word_counter;
    }

    if (fgets(words[i], MAX_WORD_SIZE, fi) == NULL) {
      return word_counter;
    }
    word_counter++;
  }
  return word_counter;
}

// return one word
char *choose_word(char **words, int n, const char *file_name) {

  int index = (rand() % n);

  int len;
  for (len = 0; len < MAX_WORD_SIZE; len++) {
    if (words[index][len] == '\n') {
      words[index][len] = '\0';
      break;
    }
    words[index][len] = tolower(words[index][len]);
  }

  if (++len < 1) {
    fprintf(stderr, "Forca: invalid word in %s", file_name);
    return NULL;
  }
  
  return words[index];
}

void free_words(char *words[], int n_words, char *word) {
  for (int i = 0; i < n_words; i++) {
    if (word != words[i]) {
      free(words[i]);
    }
  }
  free(words);
}

char *get_word(const char *file_name) {
  FILE *fi;

  if ((fi = fopen(file_name, "r")) == NULL) {
    fprintf(stderr, "Forca: failed to open %s", file_name);
    return NULL;
  }

  char **words = malloc(MAX_WORDS * sizeof(char **));
  int n_words;
  if ((n_words = read_words(fi, words)) == 0) {
    fprintf(stderr, "Forca: can't read words in %s", file_name);
  }

  char *return_word = choose_word(words, n_words, file_name);

  free_words(words, n_words, return_word);

  return return_word;
}

void drawn_hangman(int misses) {
  switch (misses) {
    case 0:
      printf("\
             +-------+\n\
             |       |\n\
             |\n\
             |\n\
             |\n\
             |\n");
    break;
    case 1:
      printf("\
             +-------+\n\
             |       |\n\
             |       O\n\
             |\n\
             |\n\
             |\n");
    break;
    case 2:
      printf("\
             +-------+\n\
             |       |\n\
             |       O\n\
             |       |\n\
             |\n\
             |\n");
    break;
    case 3:
      printf("\
             +-------+\n\
             |       |\n\
             |       O\n\
             |      /|\n\
             |\n\
             |\n");
    break;
    case 4:
      printf("\
             +-------+\n\
             |       |\n\
             |       O\n\
             |      /|\\\n\
             |\n\
             |\n");
    break;
    case 5:
      printf("\
             +-------+\n\
             |       |\n\
             |       O\n\
             |      /|\\\n\
             |        \\\n\
             |\n");
    break;
    case 6:
      printf("\
             +-------+\n\
             |       |\n\
             |       O\n\
             |      /|\\\n\
             |      / \\\n\
             |\n");
    break;
  }
}

int drawn_game(const char *file, const char *word, const char *unknown_word, const int right, const int wrong, const char *already_guessed) {
  printf("-------%s-------\n", file);
  drawn_hangman(wrong);
  printf("%s\n", unknown_word);
  printf("acertos: %d\nerros: %d\n", right, wrong);
  printf("Chutou: %s\n", already_guessed);
  printf("Chute um char ou uma palavra: ");

  if (wrong == 6) {
    printf("\n\t-------Voce Perdeu-------\n");
    printf("A palavra era: %s\n", word);
    return 0;
  }
  if (strcmp(word, unknown_word) == 0) {
      printf("\n\t-------Voce Venceu-------\n");
      return 0;
  }
  return 1;
}

void guess_char(const char guess, char *already_guessed, const char *word,
                 char *unknown_word, int *right, int *wrong) {
  if (strchr(already_guessed, guess) != NULL) {
    printf("Voce ja chutou a letra %c\n", guess);
    system("sleep 1");
    return;
  }


  int i = 0;
  while (already_guessed[i] != '\0')
    i++; 
  already_guessed[i++] = guess;
  already_guessed[i] = '\0';

  int count = 0;
  for (i = 0; word[i] != '\0'; i++) {
    if (word[i] == guess) {
      unknown_word[i] = guess;
      count++;
    }
  }
  if (count > 0)
    *right += 1;
  else
    *wrong += 1;
}

void guess_string(const char *guess, const char *word, char *unknown_word, int *wrong, int len_guess) {
  if (strcmp(word, guess) == 0) {
    strcpy(unknown_word, word);
    return;
  }

  *wrong += len_guess;

  if (*wrong > 6) {
    *wrong = 6;
  }
}

#define MAX_GUESS 1000
int take_guesses(char *already_guessed, const char *word, char *unknown_word, int *right, int *wrong) {
  int c;
  char guess[MAX_GUESS];

  int i = 0;
  while (i < MAX_GUESS && (c = getc(stdin)) != EOF && c != '\n') {
    if (isalpha(c) || c == ' ') {
      guess[i++] = tolower(c);
    }
    else {
      fprintf(stderr, "Forca: unknown char %c\n", c);
      system("sleep 1");
    }
  }

  guess[i] = '\0';
  if (c == EOF)
    return EOF;

  int len_guess;
  if ((len_guess = strlen(guess)) == 1)
    guess_char(guess[0], already_guessed, word, unknown_word, right, wrong);
  else if (len_guess > 1)
    guess_string(guess, word, unknown_word, wrong, len_guess);
  else {
    fprintf(stderr, "Forca: invalid guess %s\n", guess);
    system("sleep 1");
  }
  return 0;
}

void start_game(const char *file_name, const char *word) {
  int right = 0, wrong = 0, len = strlen(word);
  char *unknown_word = malloc(len + 1);
  char already_guessed[26] = "";

  for (int i = 0; i < len; i++) {
    unknown_word[i] = (word[i] == ' ') ? ' ' : '_';
  }
  unknown_word[len] = '\0';
  while (drawn_game(file_name, word, unknown_word, right, wrong, already_guessed)) {
    take_guesses(already_guessed, word, unknown_word, &right, &wrong);
    system("clear");
  }

  free(unknown_word);
}
