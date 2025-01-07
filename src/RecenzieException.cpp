#include "../include/RecenzieException.h"

const char *RecenzieException::what() const noexcept {
    return "Eroare: Recenzia nu poate fi adaugata!";
}
