#ifndef ERROR_HPP_
#define ERROR_HPP_

enum ErrorType {
    UNEXPECTED_CHAR
};

struct LoxError {
    ErrorType type;
    int line_num;
};

#endif // ERROR_HPP_