#include "Sticla.h"

Sticla::Sticla(std::string tip, std::string culoare, float greutate) {
    this->tip = tip;
    this->culoare = culoare;
    this->greutate = greutate;
}

Sticla::Sticla(const Sticla& other) : tip(other.tip), culoare(other.culoare), greutate(other.greutate){}

Sticla& Sticla::operator=(const Sticla& other) {
    tip = other.tip;
    culoare = other.culoare;
    greutate = other.greutate;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Sticla& sticla) {
    os << "{ tip: " << sticla.tip << ", "
       << "culoare: " << sticla.culoare << ", "
       << "greutate: " << sticla.greutate << " } \n";
    return os;
}

const std::string &Sticla::getTip() const {
    return tip;
}

const std::string &Sticla::getCuloare() const {
    return culoare;
}

float Sticla::getGreutate() const {
    return greutate;
}

void Sticla::setTip(const std::string &tip) {
    Sticla::tip = tip;
}

void Sticla::setCuloare(const std::string &culoare) {
    Sticla::culoare = culoare;
}

void Sticla::setGreutate(float greutate) {
    Sticla::greutate = greutate;
}