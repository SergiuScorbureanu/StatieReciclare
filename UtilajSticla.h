#ifndef STATIERECICLARE_UTILAJSTICLA_H
#define STATIERECICLARE_UTILAJSTICLA_H

#include "Sticla.h"
#include <iostream>
#include <string>

class UtilajSticla {
private:
    std::string nume;
    std::string producator;
    float capacitateMax; //const
    float totalReciclat;
    float totalMateriePrima;
    Sticla sticla_;

public:
    UtilajSticla() = default;
    UtilajSticla (std::string nume, std::string producator, float capacitateMax, float totalReciclat, float totalMateriePrima);
    UtilajSticla (const UtilajSticla& other);
    UtilajSticla& operator=(const UtilajSticla& other);
    ~UtilajSticla();
    friend std::ostream& operator<<(std::ostream& os, const UtilajSticla& utilajSticla);
    float getTotalReciclat() const;
    void procesare(Sticla sticla_);
    void golire();
};


#endif //STATIERECICLARE_UTILAJSTICLA_H
