#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "scanner.hpp"

void report(int line, std::string where, std::string message){
    std::cout << "[line " << line << "] Error" << where << ": " << message; 
    return;
}

int handleError(int line, std::string message) {
    report(line, "", message);
    return 1;
}

int run(std::string& source) {
    Scanner scanner(source);
    std::vector<Token> tokens = scanner.scanTokens();

    for (auto token : tokens){
        std::cout << token << std::endl;
    }
    return 0;
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