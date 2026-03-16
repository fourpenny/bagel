#ifndef SCANNER_HPP_
#define SCANNER_HPP_

#include <vector>
#include <string>

class Token {
    public:
        int x = 0;
}

class Scanner {
    public:
        Scanner(std::string source);

        std::vector<Token> scanTokens();

    private:
        std::string source;
}

#endif // SCANNER_HPP_