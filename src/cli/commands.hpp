#ifndef COMMANDS_H
#define COMMANDS_H

#include <string>

namespace strix::cli::commands {
  namespace util {
    enum class CommandType
    {
      REPL,
      UNKNOWN
    };
    
    CommandType get_command_type(std::string cmd);
  } // naamespace util
} // namespace strix::cli::commands

#endif // COMMANDS_H