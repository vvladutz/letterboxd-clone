#include <iostream>
#include "../include/Evaluari.h"
#include "../include/Film.h"
#include <string>
#include <vector>
#include <map>

Evaluari::Evaluari () {}

Evaluari &Evaluari::getEvaluare() {
    static Evaluari evaluare;
    return evaluare;
}

void Evaluari::adaugaEvaluare(const Film &film, int rating) {
    evaluari[film.getTitlu()].push_back(rating);
}

void Evaluari::afiseazaEvaluari(const Film &film) {
    if (evaluari.contains(film.getTitlu())) {
        std::cout << "evaluari pt: " << film.getTitlu() << std::endl;
        for (const auto& rating : evaluari[film.getTitlu()]) {
            std::cout << rating << std::endl;
        }
    }
    else {
        std::cout << "nu exista evaluari pt acest film!\n";
    }
}
