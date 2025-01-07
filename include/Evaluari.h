#ifndef EVALUARI_H
#define EVALUARI_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "../include/Film.h"

class Evaluari {
private:
    std::map<std::string, std::vector<int>> evaluari;
    Evaluari();
public:
    static Evaluari& getEvaluare();
    void adaugaEvaluare(const Film& film, int rating);
    void afiseazaEvaluari(const Film& film);
};

#endif //EVALUARI_H
