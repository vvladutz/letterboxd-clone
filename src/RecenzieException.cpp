#include "../include/RecenzieException.h"
#include <iostream>

const char *RecenzieException::what() const noexcept {
    return "Eroare: Recenzia nu poate fi adaugata!";
}
