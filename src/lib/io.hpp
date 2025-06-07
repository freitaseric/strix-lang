#ifndef IO_H
#define IO_H

#include <iostream>
#include <string>

namespace strix::io {
  void println(std::string str);
  void printf(const char *format, ...);

  void eprintln(std::string str);
  void eprintf(const char *format, ...);
}

#endif // IO_H