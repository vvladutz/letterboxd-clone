#ifndef COLLECTION_H
#define COLLECTION_H

#include <iostream>
#include <vector>

template <typename T>
class Collection {
private:
    std::vector<T> elemente;
public:
    Collection() = default;
    ~Collection() {
        elemente.clear();
    }

    template <typename Iterator>
    void assign(Iterator first, Iterator last) {
        elemente.assign(first, last);
    }

    template <typename Iterator>
    Collection(Iterator first, Iterator last) : elemente(first, last) {}

    void adaugaElemente(const T& element) {
        elemente.push_back(element);
    }

    template <typename U>
    friend std::istream& operator>>(std::istream&, Collection<U>&);

    auto begin() {
        return elemente.begin();
    }

    auto end() {
        return elemente.end();
    }

    auto begin() const {
        return elemente.begin();
    }

    auto end() const {
        return elemente.end();
    }

    int getSize () const {
        return elemente.size();
    }

    const T& operator[](int index) const {
        return elemente.at(index);
    }

    void clear() {
        elemente.clear();
    }
};

template <typename U>
std::istream& operator>>(std::istream& is, Collection<U>& collection) {
    U element;
    while (is >> element) {
        collection.adaugaElemente(element);
    }
    return is;
}


#endif //COLLECTION_H
