#ifndef OOP_EXCEPTII_H
#define OOP_EXCEPTII_H


class eroare_aplicatie : public std::runtime_error{
    using std::runtime_error::runtime_error;
};

class eroare_asociere_utilaje : public eroare_aplicatie {
    using eroare_aplicatie::eroare_aplicatie;
public:
    explicit eroare_asociere_utilaje(const std::string &mesaj) : eroare_aplicatie("Eroare la asocierea utilajelor catre angajati" + mesaj) {}
};

class eroare_utilaj_liber : public eroare_aplicatie {
    using eroare_aplicatie::eroare_aplicatie;
public:
    explicit eroare_utilaj_liber(const std::string &mesaj) : eroare_aplicatie("Eroare utilaj liber" + mesaj) {}
};

#endif //OOP_EXCEPTII_H
