#include "../include/Utilizator.h"
#include <iostream>
#include <vector>
#include <string>
#include "../include/Film.h"
#include "../include/Evaluari.h"

Utilizator::Utilizator(const std::string& _username, const int _varsta, const Collection<Film>& _filme_vazute) : username{std::move(_username)},
                varsta{_varsta}, filme_vazute{std::move(_filme_vazute)} {}

Utilizator::~Utilizator() {
    filme_vazute.clear();
}

Utilizator::Utilizator(const Utilizator &other) : username(other.username), varsta(other.varsta), filme_vazute(other.filme_vazute) {}


void Utilizator::afiseazaFilmeVazute() const {
        for (const auto& film : filme_vazute) {
            std::cout << film << std::endl;
        }
}

void Utilizator::evalueazaFilm(const Film &film, float rating) const {
    Evaluari::getEvaluare().adaugaEvaluare(film, rating);
    istoric.push_back(username + " a evaluat filmul " + film.getTitlu());
    std::cout << username << "(UTILIZATOR BASIC) a evaluat " << film.getTitlu() << " cu " << rating << " stele" << std::endl;
}


Utilizator& Utilizator::operator=(const Utilizator& other) {
    if (this != &other) {
        username = other.username;
        varsta = other.varsta;
        filme_vazute = other.filme_vazute;
    }
    return *this;
}

bool operator==(const Utilizator& u1, const Utilizator& u2) {
    return u1.username == u2.username && u1.varsta == u2.varsta;
}

const std::string& Utilizator::getUsername() const {
    return username;
}

int Utilizator::getRole() const {
    return 1;
}

void Utilizator::afiseazaIstoric() {
    for (const auto &i : istoric) {
        std::cout << i << std::endl;
    }
}

std::vector<std::string> Utilizator::istoric = {};


std::istream& operator>>(std::istream &in, Utilizator &util) {
    std::cout << "username:\n";
    std::getline(in, util.username, '\n');

    std::cout << "varsta:\n";
    std::cin >> util.varsta;
    std::cin.ignore();

    return in;
}

std::ostream& operator<<(std::ostream &os, const Utilizator &util) {
    util.afiseaza(os);
    return os;
}

void Utilizator::afiseaza(std::ostream &os) const {
    std::cout << "UTILIZATOR BASIC!" << std::endl;
    os << "username: " << username << std::endl;
    os << "varsta: " << varsta << std::endl;
    os << "filme vazute: ";
    for (const auto &e : filme_vazute) {
        os << e.getTitlu() << std::endl;
    }
}
