#ifndef EVALUARI_H
#define EVALUARI_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

class Evaluari {
private:
    std::map<std::string, std::vector<int>> evaluari;
    Evaluari();
public:
    static Evaluari& getEvaluare();
    void adaugaEvaluare(const std::string& film, int rating);
    void afiseazaEvaluari(const std::string& film);
};

#endif //EVALUARI_H
