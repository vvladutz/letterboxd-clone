#include <algorithm>
#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

#include "include/UtilizatorFactory.h"
#include "include/Film.h"
#include "include/Lista.h"
#include "include/Utilizator.h"
#include "include/Critic.h"
#include "include/Admin.h"
#include "include/Evaluari.h"
#include "include/RecenzieException.h"
#include "include/Recenzii.h"
#include "include/Collection.h"

void print_menu() {
    std::cout << "1. adauga film" << std::endl;
    std::cout << "2. vezi numarul de utilizatori" << std::endl;
    std::cout << "3. vezi filmele adaugate" << std::endl;
    std::cout << "4. creeaza o lista" << std::endl;
    std::cout << "5. vezi listele create" << std::endl;
    std::cout << "6. meniu utilizatori" << std::endl;
    std::cout << "7. vezi conturile create" << std::endl;
    std::cout << "8. recomandare film random" << std::endl;
    std::cout << "9. creeaza un cont" << std::endl;
    std::cout << "10. vezi evaluarile unui film" << std::endl;
    std::cout << "11. vezi recenziile unui film" << std::endl;
    std::cout << "12. vezi istoricul utilizatorilor" << std::endl;
    std::cout << "0. iesi din meniu" << std::endl;
    std::cout << "alegerea ta: \n";
}

Lista adauga_lista(Collection<Film>& filme) {
    std::string nume, description;
    std::cout << "numele listei:\n";
    std::getline(std::cin, nume, '\n');
    std::cout << "descriere:\n";
    std::getline(std::cin, description, '\n');

    std::cout << "lista creata!\n";
    return Lista(nume, description, filme);
}

Utilizator adauga_utilizator(const Collection<Film>& filme) {
    std::string nume;
    int varsta;
    std::cout << "username:\n";
    std::getline(std::cin, nume, '\n');
    std::cout << "varsta:\n";
    std::cin >> varsta;

    std::cout << "utilizator creat!\n";
    return Utilizator(nume, varsta, filme);
}

Critic adauga_critic(const Collection<Film>& filme) {
    std::string nume;
    int varsta;
    std::cout << "username:\n";
    std::getline(std::cin, nume, '\n');
    std::cout << "varsta:\n";
    std::cin >> varsta;


    std::cout << "critic creat!\n";
    return Critic(nume, varsta, filme);
}

Admin adauga_admin(const Collection<Film>& filme) {
    std::string nume;
    int varsta;
    std::cout << "username:\n";
    std::getline(std::cin, nume, '\n');
    std::cout << "varsta:\n";
    std::cin >> varsta;

    std::cout << "admin creat!\n";
    return Admin(nume, varsta, filme);
}

int check_for_movie(const Collection<Film>& filme, const std::vector<std::string>& film_list) {
    for (size_t i = 0; i < filme.getSize(); ++i) {
        for (const auto& fl : film_list) {
            if (filme[i].getTitlu() == fl) {
                return i;
            }
        }
    }
    return -1;
}


int main() {
    Collection<Film> filme;
    std::vector<std::shared_ptr<Utilizator>> utilizatori;

    filme.adaugaElemente(Film("Evil Dead 2", "Sam Raimi", 1987, 84, 4.0f));
    filme.adaugaElemente(Film("Wild Strawberries", "Ingmar Bergman", 1957, 91, 4.3f));
    filme.adaugaElemente(Film("Mystery Train", "Jim Jarmusch", 1989, 106, 4.0f));
    filme.adaugaElemente(Film("High and Low", "Akira Kurosawa", 1963, 142, 4.6f));
    filme.adaugaElemente(Film("In The Mood For Love", "Wong Kar-Wai", 2000, 99, 4.4f));
    filme.adaugaElemente(Film("Chungking Express", "Wong Kar-Wai", 1994, 103, 4.3f));
    filme.adaugaElemente(Film("Do The Right Thing", "Spike Lee", 1989, 120, 4.4f));
    filme.adaugaElemente(Film("Interstellar", "Cristopher Nolan", 2014, 169, 4.4f));
    filme.adaugaElemente(Film("Repo Man", "Alex Cox", 1984, 92, 3.7f));
    filme.adaugaElemente(Film("Aftersun", "Charlotte Wells", 2022, 101, 4.2f));
    filme.adaugaElemente(Film("The Thing", "John Carpenter", 1982, 109, 4.4f));
    filme.adaugaElemente(Film("Little Shop of Horrors", "Frank Oz", 1986, 94, 3.9f));
    filme.adaugaElemente(Film("Whiplash", "Damien Chazelle", 2014, 107, 4.4f));
    filme.adaugaElemente(Film("Twin Peaks: Fire Walk With Me", "David Lynch", 1992, 135, 4.2f));
    filme.adaugaElemente(Film("12 Angry Men", "Sidney Lumet", 1957, 97, 4.6f));
    filme.adaugaElemente(Film("A Trip To The Moon", "Georges Méliès", 1902, 15, 4.0f));
    filme.adaugaElemente(Film("Little Miss Sunshine", "Valerie Faris, Jonathan Dayton", 2006, 102, 4.2f));
    filme.adaugaElemente(Film("The End of Evangelion", "Hideaki Anno, Kazuya Tsurumaki", 1997, 87, 4.5f));
    filme.adaugaElemente(Film("House", "Nobuhiko Obayashi", 1977, 88, 4.0f));
    filme.adaugaElemente(Film("The Rocky Horror Picture Show", "Jim Sharman", 1975, 100, 4.0f));
    filme.adaugaElemente(Film("The Lord of the Rings: The Fellowship of the Ring", "Peter Jackson", 2001, 179, 4.4f));

    auto first = filme.begin() + 5;
    auto last = filme.begin() + 7;
    Collection<Film> newFilme(first, last);
    utilizatori.emplace_back(std::dynamic_pointer_cast<Utilizator>(UtilizatorFactory::creeazaUtilizator("Utilizator", "andi", 20, newFilme)));

    first = filme.begin() + 1;
    last = filme.begin() + 7;
    newFilme.assign(first, last);
    utilizatori.emplace_back(std::dynamic_pointer_cast<Utilizator>(UtilizatorFactory::creeazaUtilizator("Critic", "diana072", 21, newFilme)));



    first = filme.begin() + 10;
    last = filme.begin() + 15;
    newFilme.assign(first, last);
    utilizatori.emplace_back(std::dynamic_pointer_cast<Utilizator>(UtilizatorFactory::creeazaUtilizator("Admin", "vvladutz", 20, newFilme)));


    try {
        int raspuns;
        std::vector<Lista> lista;
        std::vector<std::string> film_lista;
        Collection<Film> lista_filme;
        std::string filmulet;
        while (true) {
            lista_filme.clear();
            print_menu();
            std::cin >> raspuns;
            std::cin.ignore();

            switch (raspuns) {
                case 0: {
                    std::cout << "multumesc pentru folosirea aplicatiei!" << std::endl;
                    return 0;
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
                        filme.adaugaElemente(f);
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
                    film_lista.clear();
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
                                lista_filme.adaugaElemente(f);
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

                case 6: {
                    int crt = 0;
                    int userId;
                    std::cout << "alege un utilizator!\n";
                    for (const auto &u : utilizatori) {
                        std::cout << ++crt << ". " << u->getUsername() << std::endl;
                    }
                    std::cin >> userId;
                    if (userId <= 0 || userId > utilizatori.size()) {
                        std::cout << "ID utilizator invalid!\n";
                        break;
                    }

                    switch (utilizatori[--userId]->getRole()) {
                        case 1: {
                            std::cout << "alege ce doresti sa faci:\n";
                            std::cout << "1. afiseaza filmele vazute\n";
                            std::cout << "2. evalueaza un film\n";
                            std::cout << "alegerea ta:\n";
                            std::cin >> raspuns;
                            switch (raspuns) {
                                case 1: {
                                    utilizatori[userId]->afiseazaFilmeVazute();
                                    break;
                                }
                                case 2: {
                                    std::cout << "ce film doresti sa evaluezi?\n";
                                    std::cin.ignore();
                                    std::getline(std::cin, filmulet, '\n');
                                    film_lista.push_back(filmulet);
                                    if (check_for_movie(filme, film_lista) != -1) {
                                        float rating;
                                        std::cout << "ce rating doresti sa ii dai?\n";
                                        std::cin >> rating;
                                        utilizatori[userId]->evalueazaFilm(filme[check_for_movie(filme, film_lista)], rating);
                                    }
                                    else std::cout << "nu am gasit filmul!\n";
                                    break;
                                }
                                default: {
                                    std::cout << "nu inteleg.\n";
                                    break;
                                }
                            }
                            break;
                        }
                        case 2: {
                            auto critic = dynamic_pointer_cast<Critic>(utilizatori[userId]);
                            std::cout << "alege ce doresti sa faci:\n";
                            std::cout << "1. afiseaza filmele vazute\n";
                            std::cout << "2. evalueaza un film\n";
                            std::cout << "3. scrie o recenzie\n";
                            std::cout << "alegerea ta:\n";
                            std::cin >> raspuns;
                            switch (raspuns) {
                                case 1: {
                                    critic->afiseazaFilmeVazute();
                                    break;
                                }
                                case 2: {
                                    std::cout << "ce film doresti sa evaluezi?\n";
                                    std::cin.ignore();
                                    std::getline(std::cin, filmulet, '\n');
                                    film_lista.push_back(filmulet);
                                    if (check_for_movie(filme, film_lista) != -1) {
                                        float rating;
                                        std::cout << "ce rating doresti sa ii dai?\n";
                                        std::cin >> rating;
                                        critic->evalueazaFilm(filme[check_for_movie(filme, film_lista)], rating);
                                    }
                                    else std::cout << "nu am gasit filmul!\n";
                                    break;
                                }
                                case 3: {
                                    std::cout << "pentru ce film doresti sa scrii o recenzie?\n";
                                    std::cin.ignore();
                                    std::getline(std::cin, filmulet, '\n');
                                    film_lista.push_back(filmulet);
                                    if (check_for_movie(filme, film_lista) != -1) {
                                        std::string recenzie;
                                        std::cout << "scrie recenzia:\n";
                                        std::getline(std::cin, recenzie, '\n');
                                        critic->scrieRecenzie(filme[check_for_movie(filme, film_lista)], recenzie);
                                    }
                                    else std::cout << "nu am gasit filmul!\n";
                                    break;
                                }
                                default: {
                                    std::cout << "nu inteleg.\n";
                                    break;
                                }
                            }
                            break;
                        }
                        case 3: {
                            std::cout << "admin!\n";
                            break;
                        }
                        default: {
                            std::cout << "nu inteleg.\n";
                            break;
                        }
                    }
                    break;
                }

                case 7: {
                    for (const auto &u : utilizatori) {
                        std::cout << *u << std::endl;
                    }
                    break;
                }

                case 8: {
                    srand(time(nullptr));
                    std::cout << filme[rand() % filme.getSize()] << std::endl;
                    break;
                }

                case 9: {
                    std::cout << "ce fel de cont doresti sa creezi?\n";
                    std::cout << "1. utilizator basic\n";
                    std::cout << "2. critic\n";
                    std::cout << "3. admin\n";
                    std::cout << "raspunsul tau:\n";
                    std::cin >> raspuns;
                    std::cin.ignore();
                    switch (raspuns) {
                        case 1: {
                            int n;
                            std::cout << "cate filme ai vazut?\n";
                            std::cin >> n;
                            std::cin.ignore();
                            std::cout << "ce filme ai vazut?\n";
                            for (int i = 0; i < n; i++) {
                                std::getline(std::cin, filmulet, '\n');
                                film_lista.push_back(filmulet);
                            }
                            int ok = 0;
                            for (const auto &f : filme) {
                                for (const auto &fl : film_lista)
                                    if (fl == f.getTitlu()) {
                                        std::cout << "film gasit!\n"; ok = 1;
                                        lista_filme.adaugaElemente(f);
                                    }
                            }
                            if (ok) {
                                utilizatori.push_back(std::make_shared<Utilizator>(adauga_utilizator(lista_filme)));
                            }
                            else std::cout << "niciun film nu a fost gasit!\n";


                            break;
                        }

                        case 2: {
                            int n;
                            std::cout << "cate filme ai vazut?\n";
                            std::cin >> n;
                            std::cin.ignore();
                            std::cout << "ce filme ai vazut?\n";
                            for (int i = 0; i < n; i++) {
                                std::getline(std::cin, filmulet, '\n');
                                film_lista.push_back(filmulet);
                            }
                            int ok = 0;
                            for (const auto &f : filme) {
                                for (const auto &fl : film_lista)
                                    if (fl == f.getTitlu()) {
                                        std::cout << "film gasit!\n"; ok = 1;
                                        lista_filme.adaugaElemente(f);
                                    }
                            }
                            if (ok) {
                                utilizatori.push_back(std::make_shared<Utilizator>(adauga_critic(lista_filme)));
                            }
                            else std::cout << "niciun film nu a fost gasit!\n";


                            break;
                        }
                        case 3: {
                            int n;
                            std::cout << "cate filme ai vazut?\n";
                            std::cin >> n;
                            std::cin.ignore();
                            std::cout << "ce filme ai vazut?\n";
                            for (int i = 0; i < n; i++) {
                                std::getline(std::cin, filmulet, '\n');
                                film_lista.push_back(filmulet);
                            }
                            int ok = 0;
                            for (const auto &f : filme) {
                                for (const auto &fl : film_lista)
                                    if (fl == f.getTitlu()) {
                                        std::cout << "film gasit!\n"; ok = 1;
                                        lista_filme.adaugaElemente(f);
                                    }
                            }
                            if (ok) {
                                utilizatori.push_back(std::make_shared<Utilizator>(adauga_admin(lista_filme)));
                            }
                            else std::cout << "niciun film nu a fost gasit!\n";
                            break;
                        }
                        default: {
                            std::cout << "nu inteleg.\n";
                            break;
                        }
                    }
                    break;
                }

                case 10: {
                    std::cout << "pentru ce film doresti sa vezi evaluarile?\n";
                    std::cin.ignore();
                    std::getline(std::cin, filmulet, '\n');
                    film_lista.push_back(filmulet);
                    if (check_for_movie(filme, film_lista) != -1) {
                        Evaluari::getEvaluare().afiseazaEvaluari(filme[check_for_movie(filme, film_lista)]);
                    }
                    else std::cout << "nu am gasit filmul!\n";
                    break;
                }

                case 11: {
                    std::cout << "pentru ce film doresti sa vezi recenziile?\n";
                    std::cin.ignore();
                    std::getline(std::cin, filmulet, '\n');
                    film_lista.push_back(filmulet);
                    if (check_for_movie(filme, film_lista) != -1) {
                        Recenzii::getRecenzie().afiseazaRecenzii(filme[check_for_movie(filme, film_lista)]);
                    }
                    else std::cout << "nu am gasit filmul!\n";
                    break;
                }

                case 12: {
                    Utilizator::afiseazaIstoric();
                    break;
                }

                default: {
                    std::cout << "nu inteleg." << std::endl;
                    break;
                }

            }
            lista_filme.clear();
            film_lista.clear();
            filmulet.clear();
        }
    }
    catch (const RecenzieException& e) {
        std::cout << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    utilizatori.clear();
    filme.clear();
}
