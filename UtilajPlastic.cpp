#include "UtilajPlastic.h"

#include <utility>
#include "Exceptii.h"

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

bool UtilajPlastic::verificare(Plastic &plastic){
    if(plastic.getTip() == "pet" || plastic.getTip() == "pete") {
        std::cout << "\n\tDeseul intra in sectiunea de * Polietilen tereftalat * pentru prelucrare.";
        return true;
    }
    else if(plastic.getTip() == "hdpe" || plastic.getTip() == "pe-hd") {
        std::cout << "\n\tDeseul intra in sectiunea de * Polietilena de inalta densitate * pentru prelucrar.";
        return true;
    }
    else if(plastic.getTip() == "pvc" || plastic.getTip() == "v") {
        std::cout << "\n\tDeseul intra in sectiunea de * Clorura de polivinil * pentru prelucrare.";
        return true;
    }
    else if(plastic.getTip() == "ldpe" || plastic.getTip() == "pe-ld") {
        std::cout << "\n\tDeseul intra in sectiunea de * Polietilena cu densitate scazuta * pentru prelucrare.";
        return true;
    }
    else if(plastic.getTip() == "pp") {
        std::cout << "\n\tDeseul intra in sectiunea de * Polipropilena * pentru prelucrare.";
        return true;
    }
    else if(plastic.getTip() == "ps") {
        std::cout << "\n\tDeseul intra in sectiunea de * Polistiren * pentru prelucrare.";
        return true;
    }
    else {
        throw eroare_deseu_plastic("\tDeseul nu poate fi reciclat!");
    }
}

void UtilajPlastic::procesare(Plastic &plastic) {
    if(plastic.getGreutate() != 0) {
        std::cout << "\n\tSe proceseaza deseul...";
        double greutateMin = plastic.getGreutate() * 0.5;
        double greutateMax = plastic.getGreutate() * 0.8;
        double greutatePierduta = greutateMin + static_cast <float> (rand()) /
                                               (static_cast <float> (RAND_MAX / (greutateMax - greutateMin)));
        plastic.setGreutate(greutatePierduta);

        this->totalReciclat++;
        this->totalMateriePrima += plastic.getGreutate();
        std::cout << "\n\tS-a obtinut o cantitate de " << plastic.getGreutate()
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

void UtilajPlastic::prelucrare(Plastic plastic) {
    if(verificare(plastic))
        procesare(plastic);

}

const std::string &UtilajPlastic::getNume() const {
    return nume;
}
