#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>

namespace strix
{
  enum class CommandType
  {
    REPL,
    UNKNOWN
  };

  /**
   * @brief Return the command type from a command string.
   */
  CommandType get_command_type(std::string command_str);

  void println(std::string str);
  void printf(const char *format, ...);

  void eprintln(std::string str);
  void eprintf(const char *format, ...);

  std::vector<std::string> split_string(const std::string &str);
} // namespace strix

#endif // !UTILS_H
