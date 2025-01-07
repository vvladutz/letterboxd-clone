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
        const int _anLansare, const int _durata, const float _rating);

    Film& operator=(const Film& other);

    bool operator<(const Film& other) const;

    friend std::ostream& operator<<(std::ostream&, const Film&);
    friend std::istream& operator>>(std::istream&, Film&);

    [[nodiscard]] std::string getTitlu() const;
    [[nodiscard]] float getRating() const;
    ~Film();
};
#endif
