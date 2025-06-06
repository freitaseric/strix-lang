#include "utils.hpp"
#include <iostream>
#include <cstdarg>
#include <sstream>

namespace strix
{
  CommandType get_command_type(std::string command_str)
  {
    if (command_str == "repl")
      return CommandType::REPL;
    else
      return CommandType::UNKNOWN;
  }

  void println(std::string str)
  {
    std::cout << str << std::endl;
  }

  void printf(const char *format, ...)
  {
    va_list args;
    va_start(args, format);

    while (*format != '\0')
    {
      if (*format == '%')
      {
        format++;
        switch (*format)
        {
        case 'd':
        {
          int i = va_arg(args, int);
          std::cout << i;
          break;
        }
        case 'c':
        {
          int c = va_arg(args, int);
          std::cout << static_cast<char>(c);
          break;
        }
        case 'f':
        {
          double d = va_arg(args, double);
          std::cout << d;
          break;
        }
        case 's':
        {
          const char *s = va_arg(args, const char *);
          std::cout << s;
          break;
        }
        default:
          std::cout << '%' << *format;
          break;
        }
      }
      else
      {
        std::cout << *format;
      }
      format++;
    }

    va_end(args);
  }

  void eprintln(std::string str)
  {
    std::cerr << str << std::endl;
  }

  void eprintf(const char *format, ...)
  {
    va_list args;
    va_start(args, format);

    while (*format != '\0')
    {
      if (*format == '%')
      {
        format++;
        switch (*format)
        {
        case 'd':
        {
          int i = va_arg(args, int);
          std::cerr << i;
          break;
        }
        case 'c':
        {
          int c = va_arg(args, int);
          std::cerr << static_cast<char>(c);
          break;
        }
        case 'f':
        {
          double d = va_arg(args, double);
          std::cerr << d;
          break;
        }
        case 's':
        {
          const char *s = va_arg(args, const char *);
          std::cerr << s;
          break;
        }
        default:
          std::cerr << '%' << *format;
          break;
        }
      }
      else
      {
        std::cerr << *format;
      }
      format++;
    }

    va_end(args);
  }

  std::vector<std::string> split_string(const std::string &str)
  {
    std::stringstream ss(str);
    std::string word;
    std::vector<std::string> result;

    while (ss >> word)
    {
      result.push_back(word);
    }

    return result;
  }
}