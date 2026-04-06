#ifndef TOKEN_HPP_
#define TOKEN_HPP_

#include <string>
#include <iostream>
#include <any>

enum TokenType {
    // Single-character tokens
    LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE,
    COMMA, DOT, MINUS, PLUS, SEMICOLON, SLASH, STAR,

    // One or two character tokens
    BANG, BANG_EQUAL,
    EQUAL, EQUAL_EQUAL,
    GREATER, GREATER_EQUAL,
    LESS, LESS_EQUAL,

    // Literals
    IDENTIFIER, STRING, NUMBER,

    // Keywords
    AND, CLASS, ELSE, FALSE, FUN, FOR, IF, NIL, OR,
    PRINT, RETURN, SUPER, THIS, TRUE, VAR, WHILE,

    EOF
};

const std::string TokenNames[] = {
    "LEFT_PAREN", "RIGHT_PAREN", "LEFT_BRACE", "RIGHT_BRACE",
    "COMMA", "DOT", "MINUS", "PLUS", "SEMICOLON", "SLASH", "STAR",

    // One or two character tokens
    "BANG", "BANG_EQUAL",
    "EQUAL", "EQUAL_EQUAL",
    "GREATER", "GREATER_EQUAL",
    "LESS", "LESS_EQUAL",

    // Literals
    "IDENTIFIER", "STRING", "NUMBER",

    // Keywords
    "AND", "CLASS", "ELSE", "FALSE", "FUN", "FOR", "IF", "NIL", "OR",
    "PRINT", "RETURN", "SUPER", "THIS", "TRUE", "VAR", "WHILE",

    "EOF"

};

class Token {
    public:
        TokenType type;
        std::string lexeme;
        // std::any literal;
        int line;

    Token(TokenType t_type, std::string lex, int line_num) : type(t_type), lexeme(lex), line(line_num) {}

    friend std::ostream& operator<<(std::ostream& os, const Token& token){
        os << "Token(" << token.lexeme << ")";
        return os;
    }

    std::string toString() {
        return TokenNames[type] + " " + lexeme;
    }
};
#endif // TOKEN_HPP_