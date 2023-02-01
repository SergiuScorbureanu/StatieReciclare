#include <iostream>
#include <string>
#include <cstdlib>
#include <random>
#include "Plastic.h"
#include "Plastic.cpp"
#include "Sticla.h"
#include "Sticla.cpp"
#include "UtilajPlastic.h"
#include "UtilajPlastic.cpp"
#include "UtilajSticla.h"
#include "UtilajSticla.cpp"

int main()
{

    //BUG-URI:
    //LA STICLA trebuie puse deseuri de aceeasi culoare in acelasi utilaj!!!

    UtilajPlastic presaPlastic = {"presa", "Bosch", 10, 0, 0};
    UtilajSticla topitorSticla = {"topitor", "Daewoo", 10, 0, 0};
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
            // Meniu pentru datele deseului
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
            presaPlastic.initializare(plastic);

        } else if (optiune == 2) {
            Sticla sticla;
            std::string tip;
            std::cout << "\n\tIntroduceti tipul deseului: ";
            std::cin >> tip;
            sticla.setTip(tip);

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
            topitorSticla.procesare(sticla);
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
        presaPlastic.golire();
    } else if (optiune == 2)
        topitorSticla.golire();


    // MENIU loop
    // 1. Variabila bool verificat rulare meniu
    // 2. Un while (isLoading)
    // 3. Prompt user (yes or no); schimb sau nu variabila de continuitate


    //------------------------------------------------------------------------------------------
    //LA STICLA trebuie puse deseuri de aceeasi culoare in acelasi utilaj!!!
}
