#include "token.hpp"
#include <string>
#include <sstream>

std::string token_type_to_string(TokenType type) {
  switch (type) {
    // Single-Char tokens
    case TokenType::LEFT_PAREN: return "LEFT_PAREN";
    case TokenType::RIGHT_PAREN: return "RIGHT_PAREN";
    case TokenType::LEFT_BRACE: return "LEFT_BRACE";
    case TokenType::RIGHT_BRACE: return "RIGHT_BRACE";
    case TokenType::COMMA: return "COMMA";
    case TokenType::DOT: return "DOT";
    case TokenType::SEMICOLON: return "SEMICOLON";
    case TokenType::MINUS: return "MINUS";
    case TokenType::PLUS: return "PLUS";
    case TokenType::SLASH: return "SLASH";
    case TokenType::STAR: return "STAR";

    // One or two chars token
    case TokenType::BANG: return "BANG";
    case TokenType::BANG_EQUAL: return "BANG_EQUAL";
    case TokenType::EQUAL: return "EQUAL";
    case TokenType::EQUAL_EQUAL: return "EQUAL_EQUAL";
    case TokenType::GREATER: return "GREATER";
    case TokenType::GREATER_EQUAL: return "GREATER_EQUAL";
    case TokenType::LESS: return "LESS";
    case TokenType::LESS_EQUAL: return "LESS_EQUAL";

    // Literals
    case TokenType::IDENTIFIER: return "IDENTIFIER";
    case TokenType::STRING: return "STRING";
    case TokenType::NUMBER: return "NUMBER";
    case TokenType::TRUE: return "TRUE";
    case TokenType::FALSE: return "FALSE";
    case TokenType::NIL: return "NIL";

    // Built-in
    case TokenType::ECHO: return "ECHO";

    // Keywords
    case TokenType::IF: return "IF";
    case TokenType::ELIF: return "ELIF";
    case TokenType::ELSE: return "ELSE";
    case TokenType::WHEN: return "WHEN";
    case TokenType::FOR: return "FOR";
    case TokenType::WHILE: return "WHILE";
    case TokenType::DO: return "DO";
    case TokenType::LOOP: return "LOOP";
    case TokenType::STATIC: return "STATIC";
    case TokenType::CLASS: return "CLASS";
    case TokenType::ENUM: return "ENUM";
    case TokenType::TYPEALIAS: return "TYPEALIAS";
    case TokenType::RETURN: return "RETURN";
    case TokenType::SUPER: return "SUPER";
    case TokenType::SELF: return "SELF";

    case TokenType::END_OF_FILE: return "END_OF_FILE";

    default: return "UNHANDLED_TOKEN_TYPE";
  }
}

Token::Token(TokenType t, std::string& le, int l, int c) : type(t), lexame(le), line(l), column(c) {}

Token::Token(TokenType t, std::string&& le, int l, int c) : type(t), lexame(std::move(le)), line(l), column(c) {}

std::string Token::to_string() const {
  std::ostringstream oss;
  oss << "Token(" << token_type_to_string(type) << ", \"" << lexame << "\"" << ", L" << line << ", C" << column << ")";
  return oss.str();
}