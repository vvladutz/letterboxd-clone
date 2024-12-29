#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "clase/Film.h"
#include "clase/Lista.h"

void print_menu() {
    std::cout << "1. adauga film" << std::endl;
    std::cout << "2. sterge film" << std::endl;
    std::cout << "3. vezi filmele adaugate" << std::endl;
    std::cout << "4. creaza o lista" << std::endl;
    std::cout << "5. vezi listele create" << std::endl;
    std::cout << "6. vezi filmele vazute" << std::endl;
    std::cout << "7. vezi filmele pe care doresti sa le vezi" << std::endl;
    std::cout << "8. recomandare film random" << std::endl;
    std::cout << "9. vezi o lista creata" << std::endl;
    std::cout << "0. iesi din meniu" << std::endl;
    std::cout << "alegerea ta: ";
}

Lista adauga_lista(std::vector<Film>& filme) {
    std::string nume, description;
    std::cout << "numele listei:\n";
    std::getline(std::cin, nume, '\n');
    std::cout << "descriere:\n";
    std::getline(std::cin, description, '\n');

    Lista l(nume, description, filme);
    std::cout << "lista creata!\n";
    return l;
}

int main() {
    int raspuns;
    std::vector<Film> filme;
    std::vector<Lista> lista;
    std::vector<std::string> film_lista;
    std::vector<Film> lista_filme;
    std::string filmulet;

    while (true) {
        lista_filme.clear();
        print_menu();
        std::cin >> raspuns;
        std::cin.ignore();
        switch (raspuns) {
            case 0: {
                std::cout << "multumesc pentru folosirea aplicatiei!" << std::endl;
                return false;
            }

            case 1: {
                Film f("", "", "", 0, 0, 0, false);
                std::cin >> f;
                int ok = 0;
                for (auto const& e : filme) {
                    if (e.getTitlu() == f.getTitlu()) {
                        ok = 1;
                        std::cout << "acest film deja exista!\n";
                        break;
                    }
                }
                if (!ok) {
                    filme.push_back(f);
                    std::cout << "film adaugat!\n";
                }
                break;
            }

            case 3: {
                std::cout << "cum vreti sa fie ordonate filmele?\n";
                std::cout << "1. in ordinea originala\n";
                std::cout << "2. dupa titlu\n";
                std::cout << "alegerea ta: ";
                std::cin >> raspuns;
                switch (raspuns) {
                    case 1: {
                        for (const auto& f : filme) {
                            std::cout << f << std::endl;
                        }
                        break;
                    }
                    case 2: {
                        std::sort(filme.begin(), filme.end());
                        for (const auto& f : filme) {
                            std::cout << f << std::endl;
                        }
                        break;
                    }
                    default: {
                        std::cout << "nu inteleg.\n";
                        break;
                    }
                }
                break;
            }

            case 4: {
                int n;
                std::cout << "cate filme doresti sa adaugi?\n";
                std::cin >> n;
                std::cout << "ce filme doresti sa adaugi? poti adauga doar filme create deja!\n";
                std::cin.ignore();
                for (int i = 0; i < n; i++) {
                    std::getline(std::cin, filmulet, '\n');
                    film_lista.push_back(filmulet);
                }
                int ok = 0;
                for (const auto &f : filme) {
                    for (const auto &fl : film_lista)
                        if (fl == f.getTitlu()) {
                            std::cout << "film gasit!\n"; ok = 1;
                            lista_filme.push_back(f);
                        }
                }
                if (ok) {
                    lista.push_back(adauga_lista(lista_filme));
                }

                else std::cout << "niciun film nu a fost gasit!\n";
                break;
            }

            case 5: {
                for (const auto& l : lista) {
                    std::cout << l << std::endl;
                }
                break;
            }

            default: {
                std::cout << "nu inteleg." << std::endl;
                break;
            }

        }
    }
}
