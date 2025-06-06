#include "repl.hpp"
#include "utils.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    strix::eprintf("Usage %s <command>\n", argv[0]);
    strix::eprintln("Available: repl");
    return 1;
  }

  strix::CommandType cmd = strix::get_command_type(argv[1]);

  switch (cmd)
  {
  case strix::CommandType::REPL:
    strix::repl();
    break;
  case strix::CommandType::UNKNOWN:
  default:
    strix::eprintf("Unknown command: %s\n", argv[1]);
    strix::eprintln("Available commands: repl");
    return 1;
  }

  return 0;
}
