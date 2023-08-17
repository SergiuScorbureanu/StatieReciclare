#include "UtilajPlastic.h"

#include <utility>

UtilajPlastic::UtilajPlastic(std::string nume, std::string producator, const int capacitateMax, int totalReciclat, float totalMateriePrima) {
    this->nume = std::move(nume);
    this->producator = std::move(producator);
    this->capacitateMax = capacitateMax;
    this->totalReciclat = totalReciclat;
    this->totalMateriePrima = totalMateriePrima;

}

UtilajPlastic::UtilajPlastic(const UtilajPlastic &other) : Utilaj(other),
        nume(other.nume), producator(other.producator), capacitateMax(other.capacitateMax),
        totalReciclat(other.totalReciclat), totalMateriePrima(other.totalMateriePrima), plastic_(other.plastic_) {}

UtilajPlastic &UtilajPlastic::operator=(const UtilajPlastic &other) {
    nume = other.nume;
    producator = other.producator;
    capacitateMax = other.capacitateMax;
    totalReciclat = other.totalReciclat;
    totalMateriePrima = other.totalMateriePrima;
    return *this;
}
UtilajPlastic::~UtilajPlastic() = default;

std::ostream& operator<<(std::ostream& os, const UtilajPlastic& utilajPlastic) {
    os << "nume: " << utilajPlastic.nume << ", "
       << "producator: " << utilajPlastic.producator << ", "
       << "capacitate maxima: " << utilajPlastic.capacitateMax << ", "
       << "total reciclat: " << utilajPlastic.totalReciclat << ", "
       << "total materie prima: " << utilajPlastic.totalMateriePrima << ", "
       << "plastic: " << utilajPlastic.plastic_ << "\n";
    return os;
}

bool UtilajPlastic::verificare(Deseu &deseu){

    auto plastic = dynamic_cast<Plastic*>(&deseu);

    if(plastic->getTip() == "pet" || plastic->getTip() == "pete") {
        std::cout << "\n\tDeseul intra in sectiunea de * Polietilen tereftalat * pentru prelucrare.";
        return true;
    }
    else if(plastic->getTip() == "hdpe" || plastic->getTip() == "pe-hd") {
        std::cout << "\n\tDeseul intra in sectiunea de * Polietilena de inalta densitate * pentru prelucrar.";
        return true;
    }
    else if(plastic->getTip() == "pvc" || plastic->getTip() == "v") {
        std::cout << "\n\tDeseul intra in sectiunea de * Clorura de polivinil * pentru prelucrare.";
        return true;
    }
    else if(plastic->getTip() == "ldpe" || plastic->getTip() == "pe-ld") {
        std::cout << "\n\tDeseul intra in sectiunea de * Polietilena cu densitate scazuta * pentru prelucrare.";
        return true;
    }
    else if(plastic->getTip() == "pp") {
        std::cout << "\n\tDeseul intra in sectiunea de * Polipropilena * pentru prelucrare.";
        return true;
    }
    else if(plastic->getTip() == "ps") {
        std::cout << "\n\tDeseul intra in sectiunea de * Polistiren * pentru prelucrare.";
        return true;
    }
    else {
        std::cerr << "\n\tDeseul introdus nu poate fi reciclat!";
        return false;
    }
}

void UtilajPlastic::procesare(Deseu &deseu) {

    auto plastic = dynamic_cast<Plastic*>(&deseu);
    if(plastic->getGreutate() != 0) {
        std::cout << "\n\tSe proceseaza deseul...";
        double greutateMin = plastic->getGreutate() * 0.5;
        double greutateMax = plastic->getGreutate() * 0.8;
        double greutatePierduta = greutateMin + static_cast <float> (rand()) /
                                               (static_cast <float> (RAND_MAX / (greutateMax - greutateMin)));
        plastic->setGreutate(greutatePierduta);

        this->totalReciclat++;
        this->totalMateriePrima += plastic->getGreutate();
        std::cout << "\n\tS-a obtinut o cantitate de " << plastic->getGreutate()
                  << " kilograme de materie prima din plastic.";

        if (totalReciclat == capacitateMax) {
            std::cout << "\n\n\tCapacitatea maxima a fost atinsa! Se initiaza procesul de golire al utilajului...\n";
            golire();
        }
    }
}

void UtilajPlastic::golire() {
    std::cout << "\tS-a obtinut un total de " << totalMateriePrima << " kilograme de materie prima din plastic.";
    totalMateriePrima = 0;
    totalReciclat = 0;
    std::cout << "\n\tUtilajul de reciclare al plasticului a fost golit." << std::endl;
}

void UtilajPlastic::prelucrare(Deseu &deseu) {

    auto plastic = dynamic_cast<Plastic*>(&deseu);
    if (plastic != nullptr) {
        if (verificare(*plastic))
            procesare(*plastic);
    }
}

void UtilajPlastic::afisare_tip_utilaj() {
    std::cout << "utilajul pentru deseurile de plastic.\n";
}
