#include "Deseu.h"

Deseu::Deseu(float greutate) : greutate(greutate) {}

Deseu::Deseu(const Deseu &other) : greutate(other.greutate) {}

Deseu &Deseu::operator=(const Deseu &other) {
    greutate = other.greutate;
    return *this;
}

Deseu::~Deseu() {}