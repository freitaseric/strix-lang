#ifndef ERRORS_H
#define ERRORS_H

#include <string>

namespace strix::errors {
  namespace tokenizer {
    void report(unsigned int line, std::string where, std::string message);
  } // namespace tokenizer
  namespace cli {
    void noargs();
    void unknowncommmand(const char *command);
  } // namespace cli
} // namespace strix::errors

#endif // ERRORS_H