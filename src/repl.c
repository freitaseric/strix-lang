#include "repl.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#define BUFFER_SIZE 2048

static char buffer[BUFFER_SIZE];

static char *readline_custom_win(char *prompt)
{
  fputs(prompt, stdout);
  fflush(stdout);
  if (fgets(buffer, BUFFER_SIZE, stdin) == NULL)
  {
    return NULL;
  }

  buffer[strcspn(buffer, "\n")] = '\0';

  char *cpy = malloc(strlen(buffer) + 1);
  if (cpy == NULL)
  {
    perror("Falha ao alocar memória para entrada");
    return NULL;
  }
  strcpy(cpy, buffer);
  return cpy;
}

static void add_history_custom_win(char *unused)
{
  (void)unused;
}

#define readline readline_custom_win
#define add_history add_history_custom_win

#else
#include <editline/readline.h>
#endif // _WIN32

void repl()
{
  printf("Strix Version %s\n", VERSION);
  puts("Press Ctrl+C (or Ctrl+D/Ctrl+Z) or type '.exit' to Exit\n");

  while (1)
  {
    char *input = readline("strix> ");

    if (input == NULL)
    {
      printf("\nExiting the Strix REPL\n");
      break;
    }

    if (strlen(input) > 0)
    {
      add_history(input);
    }

    if (strcmp(input, ".exit") == 0)
    {
      printf("Exiting the Strix REPL.\n");
      free(input);
      break;
    }

    printf("You said: %s\n", input);
    free(input);
  }
}