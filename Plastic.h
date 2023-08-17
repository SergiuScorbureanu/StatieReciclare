#ifndef STATIERECICLARE_PLASTIC_H
#define STATIERECICLARE_PLASTIC_H

#include <iostream>
#include <string>
#include "Deseu.h"

class Plastic : public Deseu {
private:
    std::string tip;
    float greutate{};

public:
    Plastic() = default;
    Plastic(std::string tip, float greutate);
    Plastic(const Plastic& other);
    Plastic& operator=(const Plastic& other);
    ~Plastic() override;

    friend std::ostream& operator<<(std::ostream& os, const Plastic& plastic);

    const std::string &getTip() const;
    float getGreutate() const;
    void setTip(const std::string &tip);
    void setGreutate(float greutate);
};

#endif //STATIERECICLARE_PLASTIC_H