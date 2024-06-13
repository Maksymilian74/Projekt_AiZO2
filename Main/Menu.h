/*
 * Klasa Menu odpowiedzialna jest za komunikacje z uzytkownikiem,
 * wybor niezbednych parametrow takich jak nazwa pliku do wczytania danych
 * i wywołanie odpowiednich metod w celu dalszej pracy
 */

#ifndef MENU_H
#define MENU_H

#include <iostream>

using namespace std;

class Menu {
public:
    // Metoda odpowiedzialna za uruchomienie glownego menu
    void runMainMenu();

private:
    // Metoda wyswietlajaca menu glowne
    int displayMainMenu();

    // Metoda wyswietlajaca menu dla trybu testowego
    int displayTestingMenu();

    // Metoda wyswietlajaca menu dla wyboru algorytmu
    int displayAlgorithmMenu();

    // Metoda wyswietlajaca menu dla trybu badawczego
    int displaySimulationMenu();
};

#endif
