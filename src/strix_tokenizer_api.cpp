#include "strix_tokenizer_api.h"
#include "token.hpp"
#include <string>
#include <vector>
#include <cstring>

static StrixTokenTypeC map_cpp_type_to_c_type(TokenType cpp_type) {
    switch (cpp_type) {
        // Single-Char tokens
        case TokenType::LEFT_PAREN:     return STRIX_TOKEN_LEFT_PAREN;
        case TokenType::RIGHT_PAREN:    return STRIX_TOKEN_RIGHT_PAREN;
        case TokenType::LEFT_BRACE:     return STRIX_TOKEN_LEFT_BRACE;
        case TokenType::RIGHT_BRACE:    return STRIX_TOKEN_RIGHT_BRACE;
        case TokenType::COMMA:          return STRIX_TOKEN_COMMA;
        case TokenType::DOT:            return STRIX_TOKEN_DOT;
        case TokenType::SEMICOLON:      return STRIX_TOKEN_SEMICOLON;
        case TokenType::MINUS:          return STRIX_TOKEN_MINUS;
        case TokenType::PLUS:           return STRIX_TOKEN_PLUS;
        case TokenType::SLASH:          return STRIX_TOKEN_SLASH;
        case TokenType::STAR:           return STRIX_TOKEN_STAR;

        // One or two chars token
        case TokenType::BANG:           return STRIX_TOKEN_BANG;
        case TokenType::BANG_EQUAL:     return STRIX_TOKEN_BANG_EQUAL;
        case TokenType::EQUAL:          return STRIX_TOKEN_EQUAL;
        case TokenType::EQUAL_EQUAL:    return STRIX_TOKEN_EQUAL_EQUAL;
        case TokenType::GREATER:        return STRIX_TOKEN_GREATER;
        case TokenType::GREATER_EQUAL:  return STRIX_TOKEN_GREATER_EQUAL;
        case TokenType::LESS:           return STRIX_TOKEN_LESS;
        case TokenType::LESS_EQUAL:     return STRIX_TOKEN_LESS_EQUAL;

        // Literals
        case TokenType::IDENTIFIER:     return STRIX_TOKEN_IDENTIFIER;
        case TokenType::STRING:         return STRIX_TOKEN_STRING;
        case TokenType::NUMBER:         return STRIX_TOKEN_NUMBER;
        case TokenType::TRUE:           return STRIX_TOKEN_TRUE;
        case TokenType::FALSE:          return STRIX_TOKEN_FALSE;
        case TokenType::NIL:            return STRIX_TOKEN_NIL;

        // Built-in
        case TokenType::ECHO:           return STRIX_TOKEN_ECHO;

        // Keywords
        case TokenType::IF:             return STRIX_TOKEN_IF;
        case TokenType::ELIF:           return STRIX_TOKEN_ELIF;
        case TokenType::ELSE:           return STRIX_TOKEN_ELSE;
        case TokenType::WHEN:           return STRIX_TOKEN_WHEN;
        case TokenType::FOR:            return STRIX_TOKEN_FOR;
        case TokenType::WHILE:          return STRIX_TOKEN_WHILE;
        case TokenType::DO:             return STRIX_TOKEN_DO;
        case TokenType::LOOP:           return STRIX_TOKEN_LOOP;
        case TokenType::STATIC:         return STRIX_TOKEN_STATIC;
        case TokenType::CLASS:          return STRIX_TOKEN_CLASS;
        case TokenType::ENUM:           return STRIX_TOKEN_ENUM;
        case TokenType::TYPEALIAS:      return STRIX_TOKEN_TYPEALIAS;
        case TokenType::RETURN:         return STRIX_TOKEN_RETURN;
        case TokenType::SUPER:          return STRIX_TOKEN_SUPER;
        case TokenType::SELF:           return STRIX_TOKEN_SELF;

        case TokenType::END_OF_FILE:    return STRIX_TOKEN_END_OF_FILE;
        
        default:
          return STRIX_TOKEN_UNKNOWN;
    }
}

const char* strix_token_type_to_string(StrixTokenTypeC type) {
    switch (type) {
        // Single-Char tokens
        case STRIX_TOKEN_LEFT_PAREN:    return "LEFT_PAREN";
        case STRIX_TOKEN_RIGHT_PAREN:   return "RIGHT_PAREN";
        case STRIX_TOKEN_LEFT_BRACE:    return "LEFT_BRACE";
        case STRIX_TOKEN_RIGHT_BRACE:   return "RIGHT_BRACE";
        case STRIX_TOKEN_COMMA:         return "COMMA";
        case STRIX_TOKEN_DOT:           return "DOT";
        case STRIX_TOKEN_SEMICOLON:     return "SEMICOLON";
        case STRIX_TOKEN_MINUS:         return "MINUS";
        case STRIX_TOKEN_PLUS:          return "PLUS";
        case STRIX_TOKEN_SLASH:         return "SLASH";
        case STRIX_TOKEN_STAR:          return "STAR";

        // One or two chars token
        case STRIX_TOKEN_BANG:          return "BANG";
        case STRIX_TOKEN_BANG_EQUAL:    return "BANG_EQUAL";
        case STRIX_TOKEN_EQUAL:         return "EQUAL";
        case STRIX_TOKEN_EQUAL_EQUAL:   return "EQUAL_EQUAL";
        case STRIX_TOKEN_GREATER:       return "GREATER";
        case STRIX_TOKEN_GREATER_EQUAL: return "GREATER_EQUAL";
        case STRIX_TOKEN_LESS:          return "LESS";
        case STRIX_TOKEN_LESS_EQUAL:    return "LESS_EQUAL";

        // Literals
        case STRIX_TOKEN_IDENTIFIER:    return "IDENTIFIER";
        case STRIX_TOKEN_STRING:        return "STRING";
        case STRIX_TOKEN_NUMBER:        return "NUMBER";
        case STRIX_TOKEN_TRUE:          return "TRUE";
        case STRIX_TOKEN_FALSE:         return "FALSE";
        case STRIX_TOKEN_NIL:           return "NIL";

        // Built-in
        case STRIX_TOKEN_ECHO:          return "ECHO";

        // Keywords
        case STRIX_TOKEN_IF:            return "IF";
        case STRIX_TOKEN_ELIF:          return "ELIF";
        case STRIX_TOKEN_ELSE:          return "ELSE";
        case STRIX_TOKEN_WHEN:          return "WHEN";
        case STRIX_TOKEN_FOR:           return "FOR";
        case STRIX_TOKEN_WHILE:         return "WHILE";
        case STRIX_TOKEN_DO:            return "DO";
        case STRIX_TOKEN_LOOP:          return "LOOP";
        case STRIX_TOKEN_STATIC:        return "STATIC";
        case STRIX_TOKEN_CLASS:         return "CLASS";
        case STRIX_TOKEN_ENUM:          return "ENUM";
        case STRIX_TOKEN_TYPEALIAS:     return "TYPEALIAS";
        case STRIX_TOKEN_RETURN:        return "RETURN";
        case STRIX_TOKEN_SUPER:         return "SUPER";
        case STRIX_TOKEN_SELF:          return "SELF";

        // Special tokens
        case STRIX_TOKEN_END_OF_FILE:   return "EOF";
        case STRIX_TOKEN_UNKNOWN:       return "UNKNOWN";
        case STRIX_TOKEN_ERROR:         return "ERROR";

        default:
            return "INVALID_TOKEN_TYPE";
    }
}
