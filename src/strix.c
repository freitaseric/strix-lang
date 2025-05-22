#define VERSION "pre_aplha"

#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#define BUFFER_SIZE 2048 
#include <string.h>

static char buffer[BUFFER_SIZE];

char* readline(char* prompt) {
  fputs(prompt, stdout);
  fgets(buffer, BUFFER_SIZE, stdin);
  char* cpy = malloc(strlen(buffer)+1);
  strcpy(cpy, buffer);
  cpy[strlen(cpy)-1] = '\0';
  return cpy;
}

void add_history(char* unused);
#else
#include <editline/readline.h>
#endif // _WIN32

int main(int argc, char **argcv)
{
  printf("Strix Version %s\n", VERSION);
  puts("Press Ctrl+c to Exit\n");

  while (1)
  {
    char *input = readline("strix> ");
    add_history(input);

    printf("No you're a %s\n", input);
    free(input);
  }

  return 0;
}
