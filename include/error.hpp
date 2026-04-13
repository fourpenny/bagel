#ifndef ERROR_HPP_
#define ERROR_HPP_

enum ErrorType {
    UNEXPECTED_CHAR
};

struct LoxError {
    ErrorType type;
    int line_num;
};

int handleError(int line, ErrorType et) {
    if (et == UNEXPECTED_CHAR){
        report(line, "", "unexpected char!");
    } else {
        report(line, "", "mysterious error...");
    }
    return 1;
}

void report(int line, std::string where, std::string message){
    std::cout << "[line " << line << "] Error" << where << ": " << message; 
    return;
}

#endif // ERROR_HPP_