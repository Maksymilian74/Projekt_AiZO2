#include "Menu.h"

class Main {
public:
    void run() {  // Metoda uruchamiajaca program
        Menu menu;
        menu.runMainMenu(); // Wywolanie metody do wyboru typu danych
    }
};

int main() {  // Glowna metoda programu
    Main main;
    main.run(); // Wywolanie metody rozpoczynajacej program
    return 0;
}


