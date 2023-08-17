#ifndef STATIERECICLARE_UTILAJSTICLA_H
#define STATIERECICLARE_UTILAJSTICLA_H

#include "Sticla.h"
#include "Utilaj.h"
#include <iostream>
#include <string>
#include <vector>

class UtilajSticla : public Utilaj {
private:
    std::string nume;
    std::string producator;
    float capacitateMax{}; //const
    float totalReciclat{};
    float totalMateriePrima{};
    Sticla sticla_;

public:
    UtilajSticla() = default;
    UtilajSticla (std::string nume, std::string producator, float capacitateMax, float totalReciclat = 0, float totalMateriePrima = 0);
    UtilajSticla (const UtilajSticla& other);
    UtilajSticla& operator=(const UtilajSticla& other);
    ~UtilajSticla();
    friend std::ostream& operator<<(std::ostream& os, const UtilajSticla& utilajSticla);
    bool verificare(Deseu &deseu) override;
    void procesare(Deseu &deseu) override;
    void golire() override;
    void prelucrare(Deseu &deseu) override;
    void afisare_tip_utilaj() override;
    std::shared_ptr<Utilaj> clone() const override
    {
        return std::make_shared<UtilajSticla>(*this);
    }
};


#endif //STATIERECICLARE_UTILAJSTICLA_H
