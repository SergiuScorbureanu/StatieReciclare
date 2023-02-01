#ifndef STATIERECICLARE_STICLA_H
#define STATIERECICLARE_STICLA_H

#include <iostream>
#include <string>

class Sticla {
private:
    std::string tip;
    std::string culoare;
    float greutate;

public:
    Sticla() = default;
    Sticla(std::string tip, std::string culoare, float greutate);
    Sticla(const Sticla& other);
    Sticla& operator=(const Sticla& other);
    ~Sticla() {}

    friend std::ostream& operator<<(std::ostream& os, const Sticla& sticla);

    const std::string &getTip() const;
    const std::string &getCuloare() const;
    float getGreutate() const;

    void setTip(const std::string &tip);
    void setCuloare(const std::string &culoare);
    void setGreutate(float greutate);
};

#endif //STATIERECICLARE_STICLA_H