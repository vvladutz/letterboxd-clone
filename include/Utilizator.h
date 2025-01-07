#ifndef UTILIZATOR_H
#define UTILIZATOR_H
#include <iostream>
#include <string>
#include <vector>
#include "Film.h"
#include "UtilizatorAbstract.h"
#include "Collection.h"

class Utilizator : public UtilizatorAbstract {
protected:
    std::string username;
    int varsta;
    Collection<Film> filme_vazute;
    static std::vector<std::string> istoric;

public:
    Utilizator(const std::string& username, const int varsta, const Collection<Film>& filme_vazute);
    virtual ~Utilizator();

    std::string getUsername() const;
    virtual int getRole() const;
    virtual void afiseazaFilmeVazute() const;
    virtual void evalueazaFilm(const Film& film, float rating) const;
    virtual void afiseaza(std::ostream &os) const override;
    static void afiseazaIstoric();

    friend bool operator==(const Utilizator& u1, const Utilizator& u2);
    friend std::ostream& operator<<(std::ostream& os, const Utilizator& util);
    friend std::istream& operator>>(std::istream&, Utilizator& util);

    Utilizator& operator=(const Utilizator& other);
};
#endif //UTILIZATOR_H!
