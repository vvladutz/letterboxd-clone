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

    filme.emplace_back("Evil Dead 2", "Sam Raimi", 1987, 84, 4.0);
    filme.emplace_back("Wild Strawberries", "Ingmar Bergman", 1957, 91, 4.3);
    filme.emplace_back("Mystery Train", "Jim Jarmusch", 1989, 106, 4.0);
    filme.emplace_back("High and Low", "Akira Kurosawa", 1963, 142, 4.6);
    filme.emplace_back("In The Mood For Love", "Wong Kar-Wai", 2000, 99, 4.4);
    filme.emplace_back("Chungking Express", "Wong Kar-Wai", 1994, 103, 4.3);
    filme.emplace_back("Do The Right Thing", "Spike Lee", 1989, 120, 4.4);
    filme.emplace_back("Interstellar", "Cristopher Nolan", 2014, 169, 4.4);
    filme.emplace_back("Repo Man", "Alex Cox", 1984, 92, 3.7);
    filme.emplace_back("Aftersun", "Charlotte Wells", 2022, 101, 4.2);
    filme.emplace_back("The Thing", "John Carpenter", 1982, 109, 4.4);
    filme.emplace_back("Little Shop of Horrors", "Frank Oz", 1986, 94, 3.9);
    filme.emplace_back("Whiplash", "Damien Chazelle", 2014, 107, 4.4);
    filme.emplace_back("Twin Peaks: Fire Walk With Me", "David Lynch", 1992, 135, 4.2);
    filme.emplace_back("12 Angry Men", "Sidney Lumet", 1957, 97, 4.6);
    filme.emplace_back("A Trip To The Moon", "Georges Méliès", 1902, 15, 4.0);
    filme.emplace_back("Little Miss Sunshine", "Valerie Faris, Jonathan Dayton", 2006, 102, 4.2);
    filme.emplace_back("The End of Evangelion", "Hideaki Anno, Kazuya Tsurumaki", 1997, 87, 4.5);
    filme.emplace_back("House", "Nobuhiko Obayashi", 1977, 88, 4.0);
    filme.emplace_back("The Rocky Horror Picture Show", "Jim Sharman", 1975, 100, 4.0);

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
                Film f("", "", 0, 0, 0);
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
