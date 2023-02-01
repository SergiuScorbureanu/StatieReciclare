#include "Plastic.h"

Plastic::Plastic(std::string tip, float greutate) {
    this->tip = tip;
    this->greutate = greutate;
}

Plastic::Plastic(const Plastic& other) : tip(other.tip), greutate(other.greutate){}

Plastic& Plastic::operator=(const Plastic& other) {
    tip = other.tip;
    greutate = other.greutate;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Plastic& plastic) {
    os << "{ tip: " << plastic.tip << ", "
       << "greutate: " << plastic.greutate << "} \n";
    return os;
}

const std::string &Plastic::getTip() const {
    return tip;
}

float Plastic::getGreutate() const {
    return greutate;
}

void Plastic::setTip(const std::string &tip) {
    Plastic::tip = tip;
}

void Plastic::setGreutate(float greutate) {
    Plastic::greutate = greutate;
}