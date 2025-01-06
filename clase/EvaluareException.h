#ifndef EVALUAREEXCEPTION_H
#define EVALUAREEXCEPTION_H

#include <iostream>
#include <exception>

class EvaluareException : public std::exception {
public:
    const char* what() const noexcept override;
};

#endif //EVALUAREEXCEPTION_H
