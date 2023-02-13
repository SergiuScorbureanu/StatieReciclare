#include "Sticla.h"

Sticla::Sticla(std::string culoare, float greutate) {
    this->culoare = culoare;
    this->greutate = greutate;
}

Sticla::Sticla(const Sticla& other) : culoare(other.culoare), greutate(other.greutate){}

Sticla& Sticla::operator= (const Sticla& other) {
    culoare = other.culoare;
    greutate = other.greutate;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Sticla& sticla) {
    os << "{ culoare: " << sticla.culoare << ", "
       << "greutate: " << sticla.greutate << " } \n";
    return os;
}


const std::string &Sticla::getCuloare() const {
    return culoare;
}

float Sticla::getGreutate() const {
    return greutate;
}

void Sticla::setCuloare(const std::string &culoare_) {
    Sticla::culoare = culoare_;
}

void Sticla::setGreutate(float greutate_) {
    Sticla::greutate = greutate_;
}