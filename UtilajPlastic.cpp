#include "UtilajPlastic.h"

UtilajPlastic::UtilajPlastic(std::string nume, std::string producator, const float capacitateMax, int totalReciclat, float totalMateriePrima)
        : capacitateMax(capacitateMax) {
    this->nume = nume;
    this->producator = producator;
    this->totalReciclat = totalReciclat;
    this->totalMateriePrima = totalMateriePrima;
}

UtilajPlastic::UtilajPlastic(const UtilajPlastic &other) :
        nume(other.nume), producator(other.producator), capacitateMax(other.capacitateMax),
        totalReciclat(other.totalReciclat), totalMateriePrima(other.totalMateriePrima), plastic_(other.plastic_) {}

UtilajPlastic &UtilajPlastic::operator=(const UtilajPlastic &other) {
    nume = other.nume;
    producator = other.producator;
    capacitateMax = other.capacitateMax;
    totalReciclat = other.totalReciclat;
    totalMateriePrima = other.totalMateriePrima;
}
UtilajPlastic::~UtilajPlastic() {}

std::ostream& operator<<(std::ostream& os, const UtilajPlastic& utilajPlastic) {
    os << "nume: " << utilajPlastic.nume << ", "
       << "producator: " << utilajPlastic.producator << ", "
       << "capacitate maxima: " << utilajPlastic.capacitateMax << ", "
       << "total reciclat: " << utilajPlastic.totalReciclat << ", "
       << "total materie prima: " << utilajPlastic.totalMateriePrima << ", "
       << "plastic: " << utilajPlastic.plastic_ << "\n";
    return os;
}

float UtilajPlastic::getTotalReciclat() const {
    return totalReciclat;
}

bool UtilajPlastic::verificare(Plastic &plastic_){
    if(plastic_.getTip() == "pet" || plastic_.getTip() == "pete") {
        std::cout << "\n\tDeseul intra in sectiunea de * Polietilen tereftalat * pentru prelucrare.";
        return true;
    }
    else if(plastic_.getTip() == "hdpe" || plastic_.getTip() == "pe-hd") {
        std::cout << "\n\tDeseul intra in sectiunea de * Polietilena de inalta densitate * pentru prelucrar.";
        return true;
    }
    else if(plastic_.getTip() == "pvc" || plastic_.getTip() == "v") {
        std::cout << "\n\tDeseul intra in sectiunea de * Clorura de polivinil * pentru prelucrare.";
        return true;
    }
    else if(plastic_.getTip() == "ldpe" || plastic_.getTip() == "pe-ld") {
        std::cout << "\n\tDeseul intra in sectiunea de * Polietilena cu densitate scazuta * pentru prelucrare.";
        return true;
    }
    else if(plastic_.getTip() == "pp") {
        std::cout << "\n\tDeseul intra in sectiunea de * Polipropilena * pentru prelucrare.";
        return true;
    }
    else if(plastic_.getTip() == "ps") {
        std::cout << "\n\tDeseul intra in sectiunea de * Polistiren * pentru prelucrare.";
        return true;
    }
    else {
        std::cout << "\n\tDeseul nu este reciclabil!";
        return false;
    }
}

void UtilajPlastic::procesare(Plastic plastic_) {
    if(plastic_.getGreutate() != 0) {
        std::cout << "\n\tSe proceseaza deseul...";
        float greutateMin = plastic_.getGreutate() * 0.5;
        float greutateMax = plastic_.getGreutate() * 0.8;
        float greutatePierduta = greutateMin + static_cast <float> (rand()) /
                                               (static_cast <float> (RAND_MAX / (greutateMax - greutateMin)));
        plastic_.setGreutate(greutatePierduta);

        this->totalReciclat++;
        this->totalMateriePrima += plastic_.getGreutate();
        std::cout << "\n\tS-a obtinut o cantitate de " << plastic_.getGreutate()
                  << " kilograme de materie prima din plastic.";

        //      if(plastic_.getTip() == "pet")

        if (totalReciclat == capacitateMax) {
            std::cout << "\n\tCapacitatea maxima a fost atinsa! Se initiaza procesul de golire al utilajului...\n";
            golire();
        }
    }
}

void UtilajPlastic::golire() {
    std::cout << "\tS-a obtinut un total de " << totalMateriePrima << " kilograme de materie prima din plastic.";
    totalMateriePrima = 0;
    totalReciclat = 0;
    std::cout << "\n\tUtilajul de reciclare al plasticului a fost golit.";
}

void UtilajPlastic::initializare(Plastic plastic_) {
    if(verificare(plastic_))
        procesare(plastic_);
}