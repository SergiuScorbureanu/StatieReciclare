#ifndef STATIERECICLARE_UTILAJPLASTIC_H
#define STATIERECICLARE_UTILAJPLASTIC_H

#include "Plastic.h"
#include "Utilaj.h"
#include <iostream>
#include <string>

class UtilajPlastic: public Utilaj{
private:
    std::string nume;
    std::string producator;
    int capacitateMax{};
    int totalReciclat{};
    float totalMateriePrima{};
    Plastic plastic_;

public:
    UtilajPlastic() = default;
    UtilajPlastic(std::string nume, std::string producator, int capacitateMax, int totalReciclat = 0, float totalMateriePrima = 0);
    UtilajPlastic (const UtilajPlastic& other);
    UtilajPlastic& operator=(const UtilajPlastic& other);
    ~UtilajPlastic();
    friend std::ostream& operator<<(std::ostream& os, const UtilajPlastic& utilajPlastic);
    bool verificare(Plastic &plastic_) override;
    void procesare(Plastic &plastic_) override;
    void golire() override;
    void prelucrare(Plastic plastic_) override;
    std::shared_ptr<Utilaj> clone() const override
    {
        return std::make_shared<UtilajPlastic>(*this);
    }
    const std::string &getNume() const;
};

#endif //STATIERECICLARE_UTILAJPLASTIC_H
