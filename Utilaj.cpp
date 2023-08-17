#include "Utilaj.h"

Utilaj::Utilaj(std::string nume, std::string producator, const int capacitateMax, int totalReciclat, float totalMateriePrima) {
    this->nume = std::move(nume);
    this->producator = std::move(producator);
    this->capacitateMax = capacitateMax;
    this->totalReciclat = totalReciclat;
    this->totalMateriePrima = totalMateriePrima;
}

Utilaj::Utilaj(const Utilaj &other) : nume(other.nume), producator(other.producator), capacitateMax(other.capacitateMax),
                                     totalReciclat(other.totalReciclat), totalMateriePrima(other.totalMateriePrima) {}

Utilaj &Utilaj::operator=(const Utilaj &other) {
    nume = other.nume;
    producator = other.producator;
    capacitateMax = other.capacitateMax;
    totalReciclat = other.totalReciclat;
    totalMateriePrima = other.totalMateriePrima;
    return *this;
}
Utilaj::~Utilaj() = default;

std::ostream& operator<<(std::ostream& os, const Utilaj& utilaj) {
    os << "nume: " << utilaj.nume << ", "
       << "producator: " << utilaj.producator << ", "
       << "capacitate maxima: " << utilaj.capacitateMax << ", "
       << "total reciclat: " << utilaj.totalReciclat << ", "
       << "total materie prima: " << utilaj.totalMateriePrima << "\n";
    return os;
}





