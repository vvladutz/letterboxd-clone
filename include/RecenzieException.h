#ifndef RECENZIEEXCEPTION_H
#define RECENZIEEXCEPTION_H

#include <exception>

class RecenzieException : public std::exception {
public:
    const char* what() const noexcept override;
};

#endif //RECENZIEEXCEPTION_H
