#include "errors.hpp"
#include "io.hpp"

namespace strix::errors {
  namespace tokenizer {
    void report(unsigned int line, std::string where, std::string message)
    {
      strix::io::eprintf("[Line %i] Error %s: %s\n", line, where, message);
    }
  }
  
  namespace cli {
    void noargs()
    {
      strix::io::eprintln("Usage: strix <command>");
      strix::io::eprintln("Available commands: repl");
    }
    
    void unknowncommand(const char *command)
    {
      strix::io::eprintf("No command '%s' available in Strix CLI!\n", command);
      strix::io::eprintln("Available commands: repl");
    }
  }
}