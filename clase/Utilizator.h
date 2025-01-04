#ifndef UTILIZATOR_H
#define UTILIZATOR_H
#include <iostream>
#include <string>
#include <vector>

#include "Film.h"

class Utilizator {
private:
    std::string username;
    int varsta;
    std::vector<Film> filme_vazute;

public:
    Utilizator(std::string& username, int varsta, std::vector<Film>& filme_vazute);
    virtual ~Utilizator();

    virtual void afiseazaFilmeVazute() const;
    virtual void evalueazaFilm(const std::string& film, float rating) const;

    friend std::ostream& operator<<(std::ostream& os, const Utilizator& l);
    friend std::istream& operator>>(std::istream&, Utilizator&);
};
#endif //UTILIZATOR_H
