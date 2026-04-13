#ifndef SCANNER_HPP_
#define SCANNER_HPP_

#include <vector>
#include <string>
#include <optional>
#include "token.hpp"
#include "error.hpp"

class Scanner {
    public:
        Scanner(std::string source);

        std::optional<LoxError> scanTokens();

        bool isAtEnd();

        void scanToken();

        void addToken(TokenType type);

        std::string advance();

    private:
        bool match(char& expected);

        std::string source;
        std::vector<Token> tokens;
        int start = 0;
        int current = 0;
        int line = 1;
};

#endif // SCANNER_HPP_