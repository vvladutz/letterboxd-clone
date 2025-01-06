#ifndef UTILIZATOR_H
#define UTILIZATOR_H
#include <iostream>
#include <string>
#include <vector>
#include "Film.h"

class Utilizator {
protected:
    std::string username;
    int varsta;
    std::vector<Film> filme_vazute;

public:
    Utilizator(const std::string& username, const int varsta, const std::vector<Film>& filme_vazute);
    virtual ~Utilizator();

    std::string getUsername() const;
    virtual int getRole() const;
    virtual void afiseazaFilmeVazute() const;
    virtual void evalueazaFilm(const Film& film, float rating) const;
    virtual void afiseaza(std::ostream &os) const;

    friend std::ostream& operator<<(std::ostream& os, const Utilizator& util);
    friend std::istream& operator>>(std::istream&, Utilizator& util);

    Utilizator& operator=(const Utilizator& other);
};
#endif //UTILIZATOR_H!
