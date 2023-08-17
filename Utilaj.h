#ifndef OOP_UTILAJ_H
#define OOP_UTILAJ_H

#include <iostream>
#include <memory>
#include "Deseu.h"

class Utilaj {

private:
    std::string nume;
    std::string producator;
    int capacitateMax{};
    int totalReciclat{};
    float totalMateriePrima{};

public:
    Utilaj() = default;
    Utilaj(std::string nume, std::string producator, int capacitateMax, int totalReciclat = 0, float totalMateriePrima = 0);
    Utilaj (const Utilaj& other);
    Utilaj& operator=(const Utilaj& other);
    virtual ~Utilaj();
    virtual std::shared_ptr<Utilaj> clone() const = 0;
    friend std::ostream& operator<<(std::ostream& os, const Utilaj& utilaj);
    virtual bool verificare(Deseu &deseu) = 0;
    virtual void procesare(Deseu &deseu) = 0;
    virtual void golire() = 0;
    virtual void prelucrare(Deseu &deseu) = 0;
};


#endif //OOP_UTILAJ_H
