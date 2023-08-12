#ifndef OOP_EXCEPTII_H
#define OOP_EXCEPTII_H


class eroare_aplicatie : public std::runtime_error{
    using std::runtime_error::runtime_error;
};

class eroare_deseu_plastic : public eroare_aplicatie {
    using eroare_aplicatie::eroare_aplicatie;
public:
    explicit eroare_deseu_plastic(const std::string &mesaj) : eroare_aplicatie("Eroare la adaugarea deseului de plastic: " + mesaj) {}
};

class eroare_deseu_sticla : public eroare_aplicatie {
    using eroare_aplicatie::eroare_aplicatie;
public:
    explicit eroare_deseu_sticla(const std::string &mesaj) : eroare_aplicatie("Eroare la adaugarea deseului de sticla" + mesaj) {}
};

class eroare_asociere_utilaje : public eroare_aplicatie {
    using eroare_aplicatie::eroare_aplicatie;
public:
    explicit eroare_asociere_utilaje(const std::string &mesaj) : eroare_aplicatie("Eroare la asocierea utilajelor catre angajati" + mesaj) {}
};
#endif //OOP_EXCEPTII_H
