#include "utils.h"
#include <string.h>
#include <stdlib.h>

CommandType get_command_type(const char *command_str)
{
  if (strcmp(command_str, "repl") == 0)
  {
    return CMD_REPL;
  }
  return CMD_UNKNOWN;
}