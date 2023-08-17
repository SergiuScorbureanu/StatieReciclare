#ifndef OOP_CREAREOBIECTE_H
#define OOP_CREAREOBIECTE_H

#include <memory>
#include "Utilaj.h"
#include "UtilajPlastic.h"
#include "UtilajSticla.h"
#include "Angajat.h"


void creare_utilaje(std::vector<std::shared_ptr<Utilaj>>& ut) {
    ut.push_back(std::make_shared<UtilajPlastic>("presa", "Hyundai", 10));
    ut.push_back(std::make_shared<UtilajPlastic>("reciclator", "Toyota", 8));
    ut.push_back(std::make_shared<UtilajSticla>("topitor", "Daewoo", 3));
    ut.push_back(std::make_shared<UtilajSticla>("presa_hidraulica", "CAT", 10));
}

void creare_angajati(std::vector<std::shared_ptr<Angajat>>& ang) {
    ang.push_back(std::make_shared<Angajat>("Popa", "Gica", 4600));
    ang.push_back(std::make_shared<Angajat>("Ionescu", "Iulian", 3800));
    ang.push_back(std::make_shared<Angajat>("Neacsu", "Radu", 4200));
    ang.push_back(std::make_shared<Angajat>("Rotaru", "Ionel", 4000));
}

void asociere_utilaje(std::vector<std::shared_ptr<Angajat>>& angajati, std::vector<std::shared_ptr<Utilaj>>& utilaje) {

    if (angajati.size() > utilaje.size()) {
        throw eroare_asociere_utilaje("\tNu exista suficiente utilaje pentru a asocia angajatilor!\n");
    }
    else if (angajati.size() < utilaje.size()) {
        throw eroare_utilaj_liber("\tExista utilaje fara om la mansa!\n");
    }
    else if (angajati.size() == utilaje.size()) {
        for (size_t i = 0; i < angajati.size(); ++i) {
            angajati[i]->asociaza_utilaj(utilaje[i]);
        }
    }
}


#endif
