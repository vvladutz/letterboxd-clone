#include <iostream>
#include <string>
#include "../include/Lista.h"
#include "../include/Film.h"
#include "../include/Collection.h"

Lista::Lista(std::string& _nume, std::string& _descriere, Collection<Film>& _filme) : nume{std::move(_nume)},
                descriere{std::move(_descriere)}, filme{std::move(_filme)} {}

std::ostream& operator<<(std::ostream &os, const Lista &l) {
    os << "nume: " << l.nume << std::endl;
    os << "descriere: " << l.descriere << std::endl;
    os << "filme: ";
    for (const auto &e : l.filme) {
        os << e.getTitlu() << std::endl;
    }
    os << "average rating: " << l.average_rating() << std::endl;
    return os;
}

std::istream& operator>>(std::istream &in, Lista &l) {
    std::cout << "numele listei:\n";
    std::getline(in, l.nume, '\n');
    std::cout << "descriere:\n";
    std::getline(in, l.descriere, '\n');

    return in;
}

std::string Lista::getNume() const {
    return nume;
}

Collection<Film> Lista::getFilme() const {
    return filme;
}


float Lista::average_rating() const {
    float avg = 0.0;
    for (const auto &f : filme) {
        avg += f.getRating();
    };

    return avg / static_cast<float>(filme.getSize());
}



Lista::~Lista() {
    filme.clear();
    std::cout << "lista stearsa!\n";
}
