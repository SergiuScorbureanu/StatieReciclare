#include <iostream>
#include <string>
#include <random>
#include "Utilaj.h"
#include "Utilaj.cpp"
#include "Deseu.h"
#include "Deseu.cpp"
#include "Plastic.h"
#include "Plastic.cpp"
#include "Sticla.h"
#include "Sticla.cpp"
#include "UtilajPlastic.h"
#include "UtilajPlastic.cpp"
#include "UtilajSticla.h"
#include "UtilajSticla.cpp"
#include "Exceptii.h"
#include "CreareObiecte.h"
#include "Angajat.h"
#include "Angajat.cpp"

int main()
{
    std::cout << "\tStare angajati si utilaje:\n";
    std::vector<std::shared_ptr<Utilaj>> utilaje;
    creare_utilaje(utilaje);

    std::vector<std::shared_ptr<Angajat>> angajati;
    creare_angajati(angajati);

    try {
        asociere_utilaje(angajati, utilaje);
        for(size_t i = 0; i < std::size(angajati); ++i) {
            angajati[i]->verificare_utilaj();
        }
    }
    catch (eroare_asociere_utilaje &err) {
        std::cout << err.what() << "\n";
    }
    catch (eroare_utilaj_liber &err) {
        std::cout << err.what() << "\n";
    }

    std::cout << "\n\t *** STATIE PENTRU RECICLARE ***\n";
    char continuare = 'd';
    do {
        int optiune;
        while (true) {
            std::cout << "\n\tAlegeti optiunea dorita:";
            std::cout << "\n\t[1] Plastic";
            std::cout << "\n\t[2] Sticla";
            std::cout << "\n\tOptiunea: ";
            if (std::cin >> optiune && (optiune == 1 || optiune ==2)) {
                break;  // intrare valida
            }
            else {
                std::cout << "\tComanda invalida. Introduceti o optiune valida!\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        if (optiune == 1) {
            // Meniu pentru datele deseului de plastic
            Plastic plastic;
            std::string tip;
            std::cout << "\n\tIntroduceti tipul deseului (pet, pvc, etc.): ";
            std::cin >> tip;
            plastic.setTip(tip);

            float greutate;
            while (true) {
                std::cout << "\tIntroduceti greutatea deseului in kg: ";
                if (std::cin >> greutate) {
                    plastic.setGreutate(greutate);
                    break;  // intrare valida
                }
                else {
                    std::cout << "\tComanda invalida. Introduceti un numar real!\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }
            utilaje[0]->prelucrare(plastic);

        } else if (optiune == 2) {
            // Meniu pentru datele deseului de sticla
            Sticla sticla;
            std::string culoare;
            std::cout << "\tIntroduceti culoarea deseului: ";
            std::cin >> culoare;
            sticla.setCuloare(culoare);

            float greutate;
            while (true) {
                std::cout << "\tIntroduceti greutatea deseului in kg: ";
                if (std::cin >> greutate) {
                    sticla.setGreutate(greutate);
                    break;
                }
                else {
                    std::cout << "\tComanda invalida. Introduceti un numar real!\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }

            utilaje[2]->prelucrare(sticla);
        }

        while (true) {
            std::cout << "\n\n\tDoriti sa adaugati alt deseu?";
            std::cout << "\n\t[d] da/[n] nu: ";
            if (std::cin >> continuare && (continuare == 'd' || continuare == 'n')) {
                break;  // intrare valida
            }
            else {
                std::cout << "\tComanda invalida. Introduceti o optiune valida!";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }

    } while(continuare == 'd');

    int optiune;
    while (true) {
        std::cout << "\n\tAlegeti optiunea dorita pentru a afla cantitatea totala de materie prima optinuta din:";
        std::cout << "\n\t[1] Plastic";
        std::cout << "\n\t[2] Sticla";
        std::cout << "\n\tOptiunea: ";
        if (std::cin >> optiune && (optiune == 1 || optiune ==2)) {
            break;  // intrare valida
        }
        else {
            std::cout << "\tComanda invalida. Introduceti o optiune valida!\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    std::cout << std::endl;
    if (optiune == 1) {
        utilaje[0]->golire();
    } else if (optiune == 2)
        utilaje[2]->golire();
}
