#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <vector>
#include <string>
#include "Utilizator.h"

class Admin : public Utilizator {
public:
    Admin(const std::string& nume, const int varsta, const std::vector<Film>& filme_vazute);
    virtual ~Admin();
    Admin(const Admin& other);
    Admin& operator=(const Admin& other);

    int getRole() const override;
    void evalueazaFilm(const Film& film, float rating) const override;
    void scrieRecenzie(const Film& film, std::string& recenzie) const;
    void stergeRecenzie(const Film& film, std::string& recenzie) const;
    void afiseaza(std::ostream &os) const override;

    friend std::ostream& operator<<(std::ostream& os, const Admin& a);
    friend std::istream& operator>>(std::istream&, Admin& a);
};

#endif //ADMIN_H
