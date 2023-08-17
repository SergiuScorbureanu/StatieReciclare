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

void Angajat::verificare_utilaj() const{

    if (utilaj_) {
        std::cout << "Angajatul " + nume + " " + prenume + " manevreaza ";
        utilaj_->afisare_tip_utilaj();
    } else {
        std::cout << "Angajatul " + nume + " " + prenume + " nu are asignat un utilaj.\n";
    }
}

//const std::shared_ptr<Utilaj> &Angajat::getUtilaj() const {
//    return utilaj_;
//}


