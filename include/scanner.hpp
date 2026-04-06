#ifndef SCANNER_HPP_
#define SCANNER_HPP_

#include <vector>
#include <string>
#include "token.hpp"

class Scanner {
    public:
        Scanner(std::string source);

        std::vector<Token> scanTokens();

        bool isAtEnd();

        void scanToken();

        void addToken(TokenType type);

        std::string advance();

    private:
        std::string source;
        std::vector<Token> tokens;
        int start = 0;
        int current = 0;
        int line = 1;
};

#endif // SCANNER_HPP_