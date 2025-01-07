#ifndef UTILIZATORFACTORY_H
#define UTILIZATORFACTORY_H
#include <memory>
#include "UtilizatorAbstract.h"
#include "Film.h"
#include "Collection.h"

class UtilizatorFactory {
public:
    static std::shared_ptr<UtilizatorAbstract> creeazaUtilizator(const std::string& tip, const std::string& nume, int varsta, Collection<Film>& filme_vazute);
};

#endif //UTILIZATORFACTORY_H
