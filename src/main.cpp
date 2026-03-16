#include <iostream>
#include <string>

void runFile(std::string path){
    // Read the file here
    // Then call "run" on the contents
    return;    
}

void runPrompt(){
    while (true) {
        std::string inputs;
        std::cout << "> ";
        std::getline(std::cin, inputs);
        if (inputs.empty()) {
            break;
        }
    }
    return;    
}

void run(std::string source) {
    return;
}

int main(int argc, char* argv[]){
    if (argc > 1){
        std::cout << "Usage: jlox [script]" << std::endl;
    } else if (argc == 1){
        std::string filename;
        filename.assign(argv[1]);
        runFile(filename);
    } else {
        runPrompt();
    }
    return 0;
}