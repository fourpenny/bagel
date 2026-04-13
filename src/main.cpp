#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <optional>

#include "scanner.hpp"
#include "error.hpp"

int run(std::string& source) {
    Scanner scanner(source);
    std::optional<LoxError> rv = scanner.scanTokens();
    if (rv.has_value()) {
        LoxError err = rv.value();
        // TODO: convert enum to error string
        handleError(err.line_num, rv);
    }

    for (auto token : tokens){
        std::cout << token << std::endl;
    }
    return rv;
}

int runFile(const std::string& path){
    int rv = 0;
    // Read the file here
    std::ifstream input(path, std::ios::binary);
    if (!input.is_open()) {
        std::cerr << "Failed to open file: " << path << std::endl;
        return 1;
    }

    std::stringstream buffer;
    buffer << input.rdbuf();
    std::string source = buffer.str();
    rv = run(source);
    // Then call "run" on the contents
    return rv;    
}

int runPrompt(){
    while (true) {
        std::string inputs;
        std::cout << "> ";
        std::getline(std::cin, inputs);
        if (inputs.empty()) {
            break;
        }
    }
    return 0;    
}

int main(int argc, char* argv[]){
    int rv = 0;
    if (argc > 1){
        std::cout << "Usage: jlox [script]" << std::endl;
    } else if (argc == 1){
        std::string filename;
        filename.assign(argv[1]);
        rv = runFile(filename);
    } else {
        rv = runPrompt();
    }
    return rv;
}