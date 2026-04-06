#include "scanner.hpp"
#include "token.hpp"

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

void Scanner::scanToken() {
    return;
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