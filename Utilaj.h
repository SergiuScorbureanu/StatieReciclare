#ifndef OOP_UTILAJ_H
#define OOP_UTILAJ_H

#include "Plastic.h"
#include <iostream>
#include <memory>

class Utilaj {

private:
    std::string nume;
    std::string producator;
    int capacitateMax{};
    int totalReciclat{};
    float totalMateriePrima{};
    Plastic plastic_;

public:
    Utilaj() = default;
    Utilaj(std::string nume, std::string producator, int capacitateMax, int totalReciclat = 0, float totalMateriePrima = 0);
    Utilaj (const Utilaj& other);
    Utilaj& operator=(const Utilaj& other);
    virtual ~Utilaj();
    virtual std::shared_ptr<Utilaj> clone() const = 0;
    friend std::ostream& operator<<(std::ostream& os, const Utilaj& utilaj);
    virtual bool verificare(Plastic &plastic_);
    virtual void procesare(Plastic &plastic_);
    virtual void golire();
    virtual void prelucrare(Plastic plastic_);
    virtual bool verificare(Sticla &sticla_);
    virtual void procesare(Sticla &sticla_);
    virtual void prelucrare(Sticla sticla_);
};


#endif //OOP_UTILAJ_H
