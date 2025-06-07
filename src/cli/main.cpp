#include "io.hpp"

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    strix::errors::cli::noargs();
    return 1;
  }

  strix::cli::commands::CommandType cmd = strix::cli::commands::get_command_type(argv[1]);

  switch (cmd)
  {
  case strix::CommandType::UNKNOWN:
  default:
    strix::errors::cli::unknowncommand(argv[1])
    return 1;
  }

  return 0;
}
