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

//bool Utilaj::verificare(Deseu &plastic) {
//    std::cout << "Utilajul verifica deseul de tip" + plastic.();;
//    return true;
//}
//
//void Utilaj::procesare(Plastic &plastic) {
//    std::cout << "Utilajul proceseaza deseul de tip " + plastic.getTip();
//}
//
//void Utilaj::golire() {
//    std::cout << "Utilajul goleste containerul";
//}
//
//void Utilaj::prelucrare(Plastic plastic) {
//    std::cout << "Utilajul prelucreaza deseul de tip " + plastic.getTip();
//}
//
//bool Utilaj::verificare(Sticla &sticla) {
//    std::cout << "Utilajul verifica deseul de culoare " + sticla.getCuloare();
//    return true;
//}
//
//void Utilaj::procesare(Sticla &sticla) {
//    std::cout << "Utilajul proceseaza deseul de culoare " + sticla.getCuloare();
//}
//
//void Utilaj::prelucrare(Sticla sticla) {
//    std::cout << "Utilajul prelucreaza deseul de culoare " + sticla.getCuloare();
//}





