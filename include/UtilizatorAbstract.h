#ifndef UTILIZATORABSTRACT_H
#define UTILIZATORABSTRACT_H

#include <iostream>

class UtilizatorAbstract {
public:
    virtual void afiseaza(std::ostream &os) const = 0;
    virtual ~UtilizatorAbstract();
};

#endif //UTILIZATORABSTRACT_H
