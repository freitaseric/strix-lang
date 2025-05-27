#include <stdio.h>
#include "utils.h"
#include "repl.h"

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    fprintf(stderr, "Usage: %s <command>\n", argv[0]);
    fprintf(stderr, "Available: repl\n");
    return 1;
  }

  CommandType cmd = get_command_type(argv[1]);

  switch (cmd)
  {
  case CMD_REPL:
    repl();
    break;
  case CMD_UNKNOWN:
  default:
    fprintf(stderr, "Unknown command: %s\n", argv[1]);
    fprintf(stderr, "Available commands: repl\n");
    return 1;
  }

  return 0;
}
