#include "../include/UtilizatorFactory.h"
#include <iostream>
#include <memory>
#include "../include/Admin.h"
#include "../include/Utilizator.h"
#include "../include/Critic.h"
#include "../include/UtilizatorAbstract.h"

std::shared_ptr<UtilizatorAbstract> UtilizatorFactory::creeazaUtilizator(const std::string &tip, const std::string& username, int varsta, Collection<Film>& filme_vazute) {
    if (tip == "Critic") {
        return dynamic_pointer_cast<UtilizatorAbstract>(std::make_shared<Critic>(username, varsta, filme_vazute));
    } else if (tip == "Admin") {
        return dynamic_pointer_cast<UtilizatorAbstract>(std::make_shared<Admin>(username, varsta, filme_vazute));
    } else {
        return dynamic_pointer_cast<UtilizatorAbstract>(std::make_shared<Utilizator>(username, varsta, filme_vazute));
    }
}
