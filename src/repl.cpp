#include "repl.hpp"
#include "utils.hpp"
#include "token.hpp"
#include <iostream>
#include <string>
#include <optional>

#ifndef _WIN32
extern "C"
{
#include <editline/readline.h>
}
#endif // !_WIN32

namespace strix
{
  std::optional<std::string> read_line(const char *prompt)
  {
#ifdef _WIN32
    std::cout << prompt << std::flush;

    std::string line;
    if (std::getline(std::cin, line))
    {
      return line;
    }
    else
    {
      return std::nullopt;
    }
#else
    char *c_input = readline(prompt);

    if (c_input == nullptr)
    {
      return std::nullopt;
    }

    std::string line(c_input);

    free(c_input);

    return line;
#endif // _WIN32
  }

  void add_to_history(const std::string &line)
  {
    if (!line.empty() && !line.find_first_not_of(" \t\n\r"))
    {
#ifndef _WIN32
      add_history(line.c_str());
#endif // !_WIN32
    }
  }

  void repl()
  {
    printf("Strix | %s\n", VERSION);
    printf("Press Ctrl+D (or type '.exit') to Exit\n\n");

    while (true)
    {
      auto line_opt = read_line("strix> ");

      if (!line_opt)
      {
        println("\nExiting Strix...");
        break;
      }

      std::string line = *line_opt;
      if (line.empty())
      {
        continue;
      }

      add_to_history(line);

      if (line == ".exit")
      {
        println("\nExiting Strix...");
        break;
      }

      auto tokens_str = split_string(line);

      for (auto token_str : tokens_str)
      {
        Token *token = new Token(TokenType::UNKOWN, token_str, 1, 1);

        std::cout << token->to_string() << std::endl;
      }
    }
  }
}