#include "UtilajSticla.h"

#include <utility>

UtilajSticla::UtilajSticla(std::string nume, std::string producator, float capacitateMax, float totalReciclat, float totalMateriePrima) {
    this->nume = std::move(nume);
    this->producator = std::move(producator);
    this->capacitateMax = capacitateMax;
    this->totalReciclat = totalReciclat;
    this->totalMateriePrima = totalMateriePrima;
}

UtilajSticla::UtilajSticla(const UtilajSticla& other) : Utilaj(other),
        nume(other.nume), producator(other.producator), capacitateMax(other.capacitateMax),
        totalReciclat(other.totalReciclat),totalMateriePrima(other.totalMateriePrima){}

UtilajSticla &UtilajSticla::operator=(const UtilajSticla& other){
    nume = other.nume;
    producator = other.producator;
    capacitateMax = other.capacitateMax;
    totalReciclat = other.totalReciclat;
    totalMateriePrima = other.totalMateriePrima;
    return *this;
}
UtilajSticla::~UtilajSticla() = default;

std::ostream& operator<<(std::ostream& os, const UtilajSticla& utilajSticla) {
    os << "nume: " << utilajSticla.nume << ", "
       << "producator: " << utilajSticla.producator << ", "
       << "capacitate maxima: " << utilajSticla.capacitateMax << ", "
       << "total reciclat: " << utilajSticla.totalReciclat << ", "
       << "total materie prima: " << utilajSticla.totalMateriePrima << "\n";
    return os;
}

bool UtilajSticla::verificare(Deseu &deseu) {

    auto sticla = dynamic_cast<Sticla*>(&deseu);
    std::vector<std::string> culori = {"rosu", "galben", "albastru", "violet", "maro"};

    for(const auto&c : culori) {
        if(c == sticla->getCuloare())
            return true;
    }
    return false;
}

void UtilajSticla::procesare(Deseu &deseu){

    auto sticla = dynamic_cast<Sticla*>(&deseu);
    std::cout << "\n\tSe proceseaza deseul din sticla...";
    double greutateMin = sticla->getGreutate() * 0.6;
    double greutateMax = sticla->getGreutate() * 0.9;
    double greutatePierduta = greutateMin + static_cast <float> (rand()) /
                                           (static_cast <float> (RAND_MAX / (greutateMax - greutateMin)));
    sticla->setGreutate(greutatePierduta);

    this->totalMateriePrima += sticla->getGreutate();
    this->totalReciclat++;
    std::cout << "\n\tS-a obtinut o cantitate de " << sticla->getGreutate()
              << " kilograme de sticla bruta.";

    if (totalReciclat == capacitateMax) {
        std::cout << "\n\n\tCapacitatea maxima a fost atinsa! Se initiaza procesul de golire al utilajului...\n";
        golire();
    }
}

void UtilajSticla::golire(){
    std::cout << "\n\tS-a obtinut un total de " << totalMateriePrima << " kilograme de sticla";
    totalMateriePrima = 0;
    totalReciclat = 0;
    std::cout << "\n\tUtilajul de reciclare a sticlei a fost golit." << std::endl;
}

void UtilajSticla::prelucrare(Deseu &deseu) {
    auto sticla = dynamic_cast<Sticla*>(&deseu);
    if (sticla != nullptr) {
        if (verificare(*sticla))
            procesare(*sticla);
        else {
            std::cerr << "\n\tDeseul introdus nu poate fi reciclat!";
        }
    }
}

void UtilajSticla::afisare_tip_utilaj() {
    std::cout << "utilajul pentru deseurile de sticla.\n";
}
