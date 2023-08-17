#include "Angajat.h"
#include "UtilajPlastic.h"

Angajat::Angajat(std::string nume, std::string prenume, int salariu) {
    this->nume = std::move(nume);
    this->prenume = std::move(prenume);
    this->salariu = salariu;
}

Angajat::Angajat(const Angajat &other) : nume(other.nume), prenume(other.prenume), salariu(other.salariu){}

Angajat &Angajat::operator=(const Angajat &other) {
    nume = other.nume;
    prenume = other.prenume;
    salariu = other.salariu;
    return *this;
}

Angajat::~Angajat() {}

std::ostream& operator<<(std::ostream& os, const Angajat& angajat) {
    os << "nume: " << angajat.nume << ", "
       << "prenume: " << angajat.prenume << ", "
       << "salariu: " << angajat.salariu << "\n";
    return os;
}

void Angajat::verificare_utilaj(const std::shared_ptr<Angajat>& angajat) {
    std::shared_ptr<Utilaj> utilaj = angajat->utilaj_;

    UtilajPlastic* utilajPlastic = dynamic_cast<UtilajPlastic*>(utilaj.get());
    if (utilajPlastic != nullptr) {
        std::cout << "\tAngajatul " + angajat->getNume() + " " + angajat->getPrenume() + " manevreaza utilajul pentru deseurile de plastic.\n";
        return;
    }

    UtilajSticla* utilajSticla = dynamic_cast<UtilajSticla*>(utilaj.get());
    if (utilajSticla != nullptr) {
        std::cout << "\tAngajatul " + angajat->getNume() + " " + angajat->getPrenume() + " manevreaza utilajul pentru deseurile de sticla.\n";
        return;
    }
}

//void verificare_utilaj(const std::shared_ptr<Angajat>& angajat) {
//    std::shared_ptr<Utilaj> utilaj = angajat->getUtilaj();
//
//    if (auto utilajPlastic = dynamic_cast<UtilajPlastic*>(utilaj.get())) {
//        std::cout << "\tAngajatul " + angajat->getNume() + " " + angajat->getPrenume() + " manevreaza utilajul pentru deseurile de plastic -> " + utilajPlastic->getNume() + "\n";
//        return;
//    }
//
//    if (auto utilajSticla = dynamic_cast<UtilajSticla*>(utilaj.get())) {
//        std::cout << "\tAngajatul " + angajat->getNume() + " " + angajat->getPrenume() + " manevreaza utilajul pentru deseurile de sticla -> "+ utilajSticla->getNume() + "\n";
//        return;
//    }
//}

const std::string &Angajat::getNume() const {
    return nume;
}

const std::string &Angajat::getPrenume() const {
    return prenume;
}

//const std::shared_ptr<Utilaj> &Angajat::getUtilaj() const {
//    return utilaj_;
//}


