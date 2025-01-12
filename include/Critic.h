#ifndef CRITIC_H
#define CRITIC_H
#include <iostream>
#include <string>
#include "Utilizator.h"
#include "Film.h"
#include "Collection.h"

class Critic : public Utilizator {
public:
    Critic(const std::string& username, const int varsta, const Collection<Film>& filme_vazute);

    ~Critic() override;
    Critic(const Critic& other);
    Critic& operator=(const Critic& other);

    int getRole() const override;
    void evalueazaFilm(const Film& film, float rating) const override;
    void scrieRecenzie(const Film& film, const std::string& recenzie) const;
    void afiseaza(std::ostream &os) const override;

    friend std::ostream& operator<<(std::ostream& os, const Critic& c);
    friend std::istream& operator>>(std::istream&, Critic& c);
};

#endif //CRITIC_H
