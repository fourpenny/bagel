#include "scanner.hpp"
#include "token.hpp"
#include "error.hpp"

Scanner::Scanner(std::string source) : source(source) {};

std::vector<Token> Scanner::scanTokens() {
    std::vector<Token> scanned_tokens{};

    while (!isAtEnd()) {
        start = current;
        scanToken();
    }

    return scanned_tokens;
}

bool Scanner::isAtEnd() {
    return current >= source.length();    
}

std::optional<LoxError> Scanner::scanToken() {
    char c = advance();
    switch (c) {
        case '(':
            addToken(TokenType::LEFT_PAREN);
            break;
        case ')':
            addToken(TokenType::RIGHT_PAREN);
            break;
        case '{':
            addToken(TokenType::LEFT_BRACE);
            break;
        case '}':
            addToken(TokenType::RIGHT_BRACE);
            break;
        case ',':
            addToken(TokenType::COMMA);
            break;
        case '.':
            addToken(TokenType::DOT);
            break;
        case '-':
            addToken(TokenType::MINUS);
            break;
        case '+':
            addToken(TokenType::PLUS);
            break;
        case ';':
            addToken(TokenType::SEMICOLON);
            break;
        case '*':
            addToken(TokenType::STAR);
            break;
        default:
            LoxError error{ErrorType::UNEXPECTED_CHAR, line};
            return error;
    }
    return {};
}

void Scanner::addToken(TokenType type) {
    int len = current - start;
    std::string text = source.substr(start, len);
    Token new_token(type, text, line);
    tokens.push_back(new_token);
    return;
}

char Scanner::advance() {
    return source.at(current++);
}