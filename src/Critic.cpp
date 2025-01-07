#include "../include/Critic.h"
#include <iostream>
#include <vector>
#include <string>
#include "../include/Film.h"
#include "../include/Evaluari.h"
#include "../include/Recenzii.h"
#include "../include/RecenzieException.h"

Critic::Critic(const std::string &username, const int varsta, const std::vector<Film> &filme_vazute) : Utilizator(username, varsta, filme_vazute) {}

Critic::~Critic() {
    filme_vazute.clear();
}

Critic::Critic(const Critic &other) : Utilizator(other) {}

Critic& Critic::operator=(const Critic &other) {
    if (this != &other) {
        Utilizator::operator=(other);
    }
    return *this;
}

void Critic::evalueazaFilm(const Film &film, float rating) const {
    Evaluari::getEvaluare().adaugaEvaluare(film, rating);
    istoric.push_back(username + " a evaluat filmul " + film.getTitlu());
    std::cout << username << "(CRITIC) a evaluat " << film << " cu " << rating << " stele" << std::endl;
}

void Critic::scrieRecenzie(const Film &film, const std::string &recenzie) const {
    if (recenzie.empty()) {
        throw RecenzieException();
    }
    Recenzii::getRecenzie().adaugaRecenzie(film, recenzie);
    istoric.push_back(username + " a scris o recenzie pentru filmul " + film.getTitlu());
    std::cout << username << "(CRITIC) A SCRIS O RECENZIE PENTRU " << film << ": " << recenzie << std::endl;
}

int Critic::getRole() const {
    return 2;
}

std::istream& operator>>(std::istream &in, Critic &c) {
    std::cout << "username:\n";
    std::getline(in, c.username, '\n');

    std::cout << "varsta:\n";
    std::cin >> c.varsta;
    std::cin.ignore();

    return in;
}

void Critic::afiseaza(std::ostream &os) const {
    std::cout << "CRITIC" << std::endl;
    os << "username: " << username << std::endl;
    os << "varsta: " << varsta << std::endl;
    os << "filme vazute: ";
    for (const auto &e : filme_vazute) {
        os << e.getTitlu() << std::endl;
    }
}