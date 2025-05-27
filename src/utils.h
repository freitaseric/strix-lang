#ifndef UTILS_H
#define UTILS_H

#include <string.h>
#include <stdlib.h>

typedef enum
{
  CMD_UNKNOWN,
  CMD_REPL
} CommandType;

CommandType get_command_type(const char *command_str);

#endif // !UTILS_H
