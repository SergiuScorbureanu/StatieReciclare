#ifndef STATIERECICLARE_STICLA_H
#define STATIERECICLARE_STICLA_H

#include <iostream>
#include <string>
#include "Deseu.h"

class Sticla : public Deseu{
private:
    std::string culoare;
    float greutate{};

public:
    Sticla() = default;
    Sticla(std::string culoare, float greutate);
    Sticla(const Sticla& other);
    Sticla& operator=(const Sticla& other);
    ~Sticla() override;

    friend std::ostream& operator<<(std::ostream& os, const Sticla& sticla);

    const std::string &getCuloare() const;
    float getGreutate() const;

    void setCuloare(const std::string &culoare);
    void setGreutate(float greutate);
};

#endif //STATIERECICLARE_STICLA_H