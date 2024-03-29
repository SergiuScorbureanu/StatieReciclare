#ifndef OOP_ANGAJAT_H
#define OOP_ANGAJAT_H

#include <iostream>
#include <memory>
#include "Utilaj.h"

class Angajat {
private:
    std::string nume;
    std::string prenume;
    unsigned int salariu;
    std::shared_ptr<Utilaj> utilaj_;

public:
    Angajat() = default;
    Angajat(std::string nume, std::string prenume, int salariu);
    Angajat (const Angajat& other);
    Angajat& operator=(const Angajat& other);
    ~Angajat();
    friend std::ostream& operator<<(std::ostream& os, const Angajat& angajat);
    void asociaza_utilaj(std::shared_ptr<Utilaj> utilaj) {
        utilaj_ = utilaj;
    }
    void verificare_utilaj() const;
};


#endif //OOP_ANGAJAT_H
