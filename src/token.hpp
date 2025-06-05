#ifndef TOKEN_H
#define TOKEN_H

#include <string>

enum class TokenType {
  // Single-Char tokens
  LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE,
  COMMA, DOT, SEMICOLON,
  MINUS, PLUS, SLASH, STAR,
  
  // One or two chars token
  BANG, BANG_EQUAL,
  EQUAL, EQUAL_EQUAL,
  GREATER, GREATER_EQUAL,
  LESS, LESS_EQUAL,
  
  // Literals
  IDENTIFIER, STRING, NUMBER, TRUE, FALSE, NIL,
  
  // Built-in
  ECHO,
  
  // Keywords
  IF, ELIF, ELSE, WHEN,
  FOR, WHILE, DO, LOOP,
  STATIC, CLASS, ENUM, TYPEALIAS,
  RETURN, SUPER, SELF,

  END_OF_FILE,
  UNKOWN,
  ERROR
};

std::string token_type_to_string(TokenType type);

class Token {
  public:
    TokenType type;
    std::string lexame;
    int line;
    int column;
    
    Token(TokenType type, std::string& lexame, int line, int column);
    Token(TokenType typr, std::string&& lexame, int line, int column);
    
    std::string to_string() const;
};

#endif // TOKEN_H