#ifndef STATIERECICLARE_UTILAJPLASTIC_H
#define STATIERECICLARE_UTILAJPLASTIC_H

#include "Plastic.h"
#include <iostream>
#include <string>

class UtilajPlastic{
private:
    std::string nume;
    std::string producator;
    float capacitateMax;
    int totalReciclat;
    float totalMateriePrima;
    Plastic plastic_;

public:
    UtilajPlastic() = default;
    UtilajPlastic(std::string nume, std::string producator, const float capacitateMax, int totalReciclat, float totalMateriePrima);
    UtilajPlastic (const UtilajPlastic& other);
    UtilajPlastic& operator=(const UtilajPlastic& other);
    ~UtilajPlastic();
    friend std::ostream& operator<<(std::ostream& os, const UtilajPlastic& utilajPlastic);
    float getTotalReciclat() const;
    bool verificare(Plastic &plastic_);
    void procesare(Plastic plastic_);
    void golire();
    void initializare(Plastic plastic_);
};

#endif //STATIERECICLARE_UTILAJPLASTIC_H
