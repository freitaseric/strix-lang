#include "commands.hpp"

namespace strix::cli::commands {
  namespace util {
    CommandType get_command_type(std::string cmd)
    {
      switch (cmd)
      {
        case "repl":
          return CommandType::REPL;
          
        default:
          return CommandType::UNKNOWN;
      }
    }
  }
}