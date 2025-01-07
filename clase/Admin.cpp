#include "Admin.h"
#include <iostream>
#include <vector>
#include <string>
#include "Film.h"
#include "Evaluari.h"
#include "Recenzii.h"
#include "RecenzieException.h"

Admin::Admin(const std::string &username, const int varsta, const std::vector<Film> &filme_vazute) : Utilizator(username, varsta, filme_vazute) {}

Admin::~Admin() {
    filme_vazute.clear();
}

Admin::Admin(const Admin& other) : Utilizator(other) {}

Admin& Admin::operator=(const Admin& other) {
    if (this != &other) {
        Utilizator::operator=(other);
    }
    return *this;
}

void Admin::evalueazaFilm(const Film& film, float rating) const {
    Evaluari::getEvaluare().adaugaEvaluare(film, rating);
    istoric.push_back(username + " a evaluat filmul " + film.getTitlu());
    std::cout << username << "(ADMIN) a evaluat " << film.getTitlu() << " cu " << rating << " stele" << std::endl;
}

void Admin::scrieRecenzie(const Film& film, std::string& recenzie) const {
    if (recenzie.empty()) {
        throw RecenzieException();
    }
    std::cout << username << "(ADMIN) A SCRIS O RECENZIE PENTRU " << film.getTitlu() << ": " << recenzie << std::endl;
    istoric.push_back(username + " a scris o recenzie pentru filmul " + film.getTitlu());
    Recenzii::getRecenzie().adaugaRecenzie(film, recenzie);
}

void Admin::stergeRecenzie(const Film& film, std::string &recenzie) const {
    Recenzii::getRecenzie().stergeRecenzie(film, recenzie);
    istoric.push_back(username + " a sters o recenzie pentru filmul " + film.getTitlu());
    std::cout << username << " (ADMIN) A STERS RECENZIA PENTRU " << film.getTitlu() << std::endl;
}

int Admin::getRole() const {
    return 3;
}

void Admin::afiseaza(std::ostream &os) const {
    std::cout << "ADMIN" << std::endl;
    os << "username: " << username << std::endl;
    os << "varsta: " << varsta << std::endl;
    os << "filme vazute: ";
    for (const auto &e : filme_vazute) {
        os << e.getTitlu() << std::endl;
    }
}

std::istream& operator>>(std::istream &in, Admin &a) {
    std::cout << "username:\n";
    std::getline(in, a.username, '\n');

    std::cout << "varsta:\n";
    std::cin >> a.varsta;
    std::cin.ignore();

    return in;
}
