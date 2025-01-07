#ifndef FILM_H
#define FILM_H

#include <iostream>
#include <string>

class Film {
private:
    std::string titlu;
    std::string regizor;
    int anLansare;
    int durata;
    float rating;
public:
    Film(const std::string& _titlu="", const std::string& _regizor="",
        const int _anLansare=0, const int _durata=0, const float _rating=0);

    Film& operator=(const Film& other);

    bool operator<(const Film& other) const;

    friend std::ostream& operator<<(std::ostream&, const Film&);
    friend std::istream& operator>>(std::istream&, Film&);

    [[nodiscard]] std::string getTitlu() const;
    [[nodiscard]] float getRating() const;
    ~Film();
};
#endif
