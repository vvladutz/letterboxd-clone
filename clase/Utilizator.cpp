#include "Utilizator.h"
#include <iostream>
#include <vector>
#include <string>
#include "Film.h"
#include "Evaluari.h"

Utilizator::Utilizator(std::string& _username, int _varsta, std::vector<Film>& _filme_vazute) : username{std::move(_username)},
                varsta{_varsta}, filme_vazute{std::move(_filme_vazute)} {}

Utilizator::~Utilizator() {
    filme_vazute.clear();
}

void Utilizator::afiseazaFilmeVazute() const {
        for (auto& film : filme_vazute) {
            std::cout << film << std::endl;
        }
}

void Utilizator::evalueazaFilm(const std::string &film, float rating) const {
    Evaluari::getEvaluare().adaugaEvaluare(film, rating);
    std::cout << username << "(UTILIZATOR BASIC) a evaluat " << film << " cu " << rating << " stele" << std::endl;
}


Utilizator& Utilizator::operator=(const Utilizator& other) {
    if (this != &other) {
        username = other.username;
        varsta = other.varsta;
        filme_vazute = other.filme_vazute;
    }
    return *this;
}

std::istream& operator>>(std::istream &in, Utilizator &util) {
    std::cout << "username:\n";
    std::getline(in, util.username, '\n');

    std::cout << "varsta:\n";
    std::cin >> util.varsta;
    std::cin.ignore();

    return in;
}

std::ostream& operator<<(std::ostream &os, const Utilizator &u) {
    os << "username: " << u.username << std::endl;
    os << "varsta: " << u.varsta << std::endl;
    os << "filme vazute: ";
    for (const auto &e : u.filme_vazute) {
        os << e.getTitlu() << std::endl;
    }
    return os;
}