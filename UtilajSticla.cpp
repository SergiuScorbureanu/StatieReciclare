#include "UtilajSticla.h"

UtilajSticla::UtilajSticla(std::string nume, std::string producator, float capacitateMax, float totalReciclat, float totalMateriePrima) {
    this->nume = nume;
    this->producator = producator;
    this->capacitateMax = capacitateMax;
    this->totalReciclat = totalReciclat;
    this->totalMateriePrima = totalMateriePrima;
}

UtilajSticla::UtilajSticla(const UtilajSticla& other) :
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
UtilajSticla::~UtilajSticla() {}

std::ostream& operator<<(std::ostream& os, const UtilajSticla& utilajSticla) {
    os << "nume: " << utilajSticla.nume << ", "
       << "producator: " << utilajSticla.producator << ", "
       << "capacitate maxima: " << utilajSticla.capacitateMax << ", "
       << "total reciclat: " << utilajSticla.totalReciclat << ", "
       << "total materie prima: " << utilajSticla.totalMateriePrima << "\n";
    return os;
}

float UtilajSticla::getTotalReciclat() const {
    return totalReciclat;
}

void UtilajSticla::procesare(Sticla sticla){

    std::cout << "\n\tSe proceseaza deseul din sticla...";
    float greutateMin = sticla.getGreutate() * 0.6;
    float greutateMax = sticla.getGreutate() * 0.9;
    float greutatePierduta = greutateMin + static_cast <float> (rand()) /
                                           (static_cast <float> (RAND_MAX / (greutateMax - greutateMin)));
    sticla.setGreutate(greutatePierduta);

    this->totalMateriePrima += sticla.getGreutate();
    this->totalReciclat++;
    std::cout << "\n\tS-a obtinut o cantitate de " << sticla.getGreutate()
              << " kilograme de sticla bruta.";

    if (totalReciclat == capacitateMax) {
        std::cout << "\n\tCapacitatea maxima a fost atinsa! Se initiaza procesul de golire al utilajului...\n";
        golire();
    }
}

void UtilajSticla::golire(){
    std::cout << "\n\tS-a obtinut un total de " << totalMateriePrima << " kilograme de sticla de culoare " << sticla_.getCuloare() << std::endl;
    totalMateriePrima = 0;
    totalReciclat = 0;
    std::cout << "\tUtilajul de reciclare a sticlei a fost golit.";
}