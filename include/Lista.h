#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include <string>
#include "../include/Film.h"
#include "../include/Collection.h"

class Lista {
private:
    std::string nume;
    std::string descriere;
    Collection<Film> filme;
public:
    Lista(std::string& _nume, std::string& _descriere, Collection<Film>& _filme);
    ~Lista();

    friend std::ostream& operator<<(std::ostream& os, const Lista& l);
    friend std::istream& operator>>(std::istream&, Lista &l);

    [[nodiscard]] float average_rating() const;

};

#endif
