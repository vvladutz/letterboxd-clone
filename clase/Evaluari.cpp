#include <iostream>
#include "Evaluari.h"
#include <string>
#include <vector>
#include <map>

Evaluari::Evaluari () {}

Evaluari &Evaluari::getEvaluare() {
    static Evaluari evaluare;
    return evaluare;
}

void Evaluari::adaugaEvaluare(const std::string &film, int rating) {
    evaluari[film].push_back(rating);
}

void Evaluari::afiseazaEvaluari(const std::string &film) {
    if (evaluari.find(film) != evaluari.end()) {
        std::cout << "evaluari pt: " << film << std::endl;
        for (const auto& rating : evaluari[film]) {
            std::cout << rating << std::endl;
        }
    }
    else {
        std::cout << "nu exista evaluari pt acest film!\n";
    }
}
