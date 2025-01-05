#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include <string>
#include <vector>
#include "Film.h"

class Lista {
private:
    std::string nume;
    std::string descriere;
    std::vector<Film> filme;
public:
    Lista(std::string& _nume, std::string& _descriere, std::vector<Film>& _filme);
    ~Lista();

    [[nodiscard]] std::string getNume() const;

    [[nodiscard]] std::vector<Film> getFilme() const;

    friend std::ostream& operator<<(std::ostream& os, const Lista& l);
    friend std::istream& operator>>(std::istream&, Lista &l);

    [[nodiscard]] float average_rating() const;

};

#endif
