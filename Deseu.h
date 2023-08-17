#ifndef OOP_DESEU_H
#define OOP_DESEU_H


class Deseu {

private:
    float greutate{};
public:
    Deseu() = default;
    explicit Deseu(float greutate);
    Deseu (const Deseu& other);
    Deseu& operator=(const Deseu &other);
    virtual ~Deseu();
};


#endif //OOP_DESEU_H
