#ifndef SCANNER_HPP_
#define SCANNER_HPP_

#include <vector>
#include <string>
#include <iostream>

class Token {
    public:
        std::string rep{};

    friend std::ostream& operator<<(std::ostream& os, const Token& token){
        os << "Token(" << token.rep << ")";
        return os;
    }
};

class Scanner {
    public:
        Scanner(std::string source);

        std::vector<Token> scanTokens();

    private:
        std::string source;
};

#endif // SCANNER_HPP_