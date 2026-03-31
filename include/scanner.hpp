#ifndef SCANNER_HPP_
#define SCANNER_HPP_

#include <vector>
#include <string>
#include "token.hpp"

class Scanner {
    public:
        Scanner(std::string source);

        std::vector<Token> scanTokens();

    private:
        std::string source;
};

#endif // SCANNER_HPP_