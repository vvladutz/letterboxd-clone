#include <iostream>
#include "../include/Recenzii.h"
#include <string>
#include <vector>
#include <map>
#include <algorithm>

Recenzii::Recenzii() {}

Recenzii &Recenzii::getRecenzie() {
    static Recenzii recenzie;
    return recenzie;
}

void Recenzii::adaugaRecenzie(const Film &film, std::string& recenzie) {
    recenzii[film.getTitlu()].push_back(recenzie);
}

void Recenzii::afiseazaRecenzii(const Film &film) {
    if (recenzii.find(film.getTitlu()) != recenzii.end()) {
        std::cout << "recenzii pt: " << film.getTitlu() << std::endl;
        for (const auto& rating : recenzii[film.getTitlu()]) {
            std::cout << rating << std::endl;
        }
    }
    else {
        std::cout << "nu exista recenzii pt acest film!\n";
    }
}

void Recenzii::stergeRecenzie(const Film &film, std::string& recenzie) {
    if (recenzii.find(film.getTitlu()) != recenzii.end()) {
        auto it = std::find(recenzii[film.getTitlu()].begin(), recenzii[film.getTitlu()].end(), recenzie);
        if (it != recenzii[film.getTitlu()].end()) {
            recenzii[film.getTitlu()].erase(it);
        } else {
            std::cout << "recenzia nu a fost gasita!\n";
        }
    }
    else {
        std::cout << "nu exista recenzii pt acest film!\n";
    }
}