#ifndef RECENZII_H
#define RECENZII_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Film.h"

class Recenzii {
private:
    std::map<std::string, std::vector<std::string>> recenzii;
    Recenzii();
public:
    static Recenzii& getRecenzie();
    void adaugaRecenzie(const Film& film, std::string& recenzie);
    void afiseazaRecenzii(const Film& film);
    void stergeRecenzie(const Film &film, std::string& recenzie);
};


#endif //RECENZII_H
