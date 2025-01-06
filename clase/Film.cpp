#include "Film.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

Film::Film(const std::string& _titlu="", const std::string& _regizor="",
        const int _anLansare=0, const int _durata=0, const float _rating=0)
    : titlu{_titlu}, regizor{_regizor}, anLansare{_anLansare}, durata{_durata}, rating{_rating} {}

Film& Film::operator=(const Film& other) {
    this->titlu = other.titlu;
    this->regizor = other.regizor;
    this->anLansare = other.anLansare;
    this->durata = other.durata;
    this->rating = other.rating;
    return *this;
}

bool Film::operator< (const Film &other) const {
    return (this->titlu < other.titlu);
}


std::ostream& operator<<(std::ostream &os, const Film &film) {
    os << "filmul " << film.titlu << " regizat de " << film.regizor << std::endl;
    os << "anul lansarii: " << film.anLansare << std::endl;
    if (film.durata > 60) {
        os << "durata: " << film.durata/60 << "h ";
        (film.durata % 60 > 0) ? os << film.durata%60 << "m\n" : os << std::endl;
    }
    else os << "durata: " << film.durata%60 << " min\n";
    os << "rating: " << film.rating << std::endl;
    return os;
}

std::istream& operator>>(std::istream &in, Film &film) {
    std::cout << "titlul filmului:\n";
    std::getline(in, film.titlu, '\n');

    std::cout << "regizorul filmului:\n";
    std::getline(in, film.regizor);

    std::cout << "an lansare:\n";
    in >> film.anLansare;

    std::cout << "durata filmului:\n";
    in >> film.durata;
    std::cout << "rating:\n";
    in >> film.rating;
    std::cout << "vazut (1) / doresc sa il vad (0):\n";
    in >> film.vazut;
    return in;
}

float Film::getRating() const {
    return this->rating;
}

std::string Film::getTitlu() const {
    return this->titlu;
}

Film::~Film() {}
