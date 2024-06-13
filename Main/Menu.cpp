#include "Menu.h"
#include "../Submenu/TestSolving.h"
#include "../Submenu/SimulationSolving.h"
#include <iostream>

using namespace std;

void Menu::runMainMenu() { // Implementacja glownego menu
    int number;
    int test;
    int simulation;
    int algorithm;
    int vertices;
    int density;
    string fileToOpen;
    TestSolving* testSolving = nullptr;
    SimulationSolving* simulationSolving = nullptr;

    do {
        number = displayMainMenu(); // Wyswietlenie glownego menu
        switch (number) {
            case 1:
                cout << "-------------------------------------------\n";
                cout << "Tryb pracy testowej\n";
                testSolving = new TestSolving(); // Utworzenie obiektu klasy TestSolving
                do {
                    test = displayTestingMenu(); // Wyswieltenie menu dla trybu testowania
                    switch (test) {
                        case 1:
                            cout << "-------------------------------------------\n";
                            cout << "Wczytanie danych z pliku\n";
                            cout << "Podaj nazwe pliku z rozszerzeniem\n";
                            cin >> fileToOpen;
                            testSolving->loadDataFromFile(fileToOpen);
                            break;
                        case 2:
                            cout << "-------------------------------------------\n";
                            cout << "Wygenerowanie grafu losowo\n";
                            cout << "Podaj liczbe wierzcholkow\n";
                            cin >> vertices;
                            cout << "Podaj gestosc grafu\n";
                            cin >> density;
                            testSolving->generateRandomGraph(vertices, density);
                            break;
                        case 3:
                            cout << "-------------------------------------------\n";
                            cout << "Wyswietlenie grafu\n";
                            testSolving->displayGraph();
                            break;
                        case 4:
                            cout << "-------------------------------------------\n";
                            cout << "Algorytm Prima\n";
                            testSolving->algorithmPrim();
                            break;
                        case 5:
                            cout << "Algorytm Kruskala\n";
                            testSolving->algorithmKruskal();
                            break;
                        case 6:
                            cout << "-------------------------------------------\n";
                            cout << "Algorytm Dijkstry\n";
                            testSolving->algorithmDijkstra();
                            break;
                        case 7:
                            cout << "-------------------------------------------\n";
                            cout << "Algorytm Forda-Bellmana\n";
                            testSolving->algorithmFordBellman();
                            break;
                        case 8:
                            cout << "-------------------------------------------\n";
                            cout << "Wyjscie do wyboru trybu pracy  \n";
                            break;
                        default:
                            cout << "-------------------------------------------\n";
                            cout << "Bledny numer, podaj prawidlowa wartosc\n";
                            break;
                    }
                } while(test != 8);
                delete testSolving;  // Zwolnieni pamieci po obiekcie TestSolving
                testSolving = nullptr; // Ustawienie wskaznika na nullptr
                break;
            case 2:
                cout << "-------------------------------------------\n";
                cout << "Tryb pracy badawczej\n";
                simulationSolving = new SimulationSolving(); // Utworzenie obiektu klasy SimulationSolving
                do {
                    simulation = displaySimulationMenu(); // Wyswietlenie menu dla trybu badawczego
                    switch (simulation) {
                        case 1:
                            cout << "-------------------------------------------\n";
                            cout << "Wybor algorytmu\n";
                            algorithm = displayAlgorithmMenu(); // Wyswietlenie menu do wyboru problemu badawczego
                            simulationSolving->testAlgorithm(algorithm);
                            break;
                        case 2:
                            cout << "-------------------------------------------\n";
                            cout << "Wyjscie do wyboru trybu pracy  \n";
                            break;
                        default:
                            cout << "-------------------------------------------\n";
                            cout << "Bledny numer, podaj prawidlowa wartosc\n";
                            break;
                    }
                } while(simulation != 2);
                delete simulationSolving;  // Zwolnieni pamieci po obiekcie SimulationSolving
                simulationSolving = nullptr; // Ustawienie wskaznika na nullptr
                break;
            case 3:
                cout << "-------------------------------------------\n";
                cout << "Zakonczenie dzialania programu\n";
                break;
            default:
                cout << "-------------------------------------------\n";
                cout << "Bledny numer, podaj prawidlowa wartosc\n";
                break;
        }
    } while (number != 3);


}

int Menu::displayMainMenu() { // Implementacja wyswietlania glownego menu
    int task;
    cout << "---------------------------\n";
    cout << "     --- Main Menu ---     \n";
    cout << "1. Tryb pracy testowej     \n";
    cout << "2. Tryb pracy badawczej    \n";
    cout << "3. Wyjscie                 \n";
    cout << "Wpisz numer zadania:";
    cin >> task;
    return task;
}

int Menu::displayTestingMenu() { // Implementacja wyswietlania menu dla trybu testowego
    int task;
    cout << "------------------------------------------------\n";
    cout << "            --- Testing Menu ---                \n";
    cout << "1. Wczytanie danych z pliku                     \n";
    cout << "2. Wygenerowanie grafu losowo                   \n";
    cout << "3. Wyswietlenie grafu                           \n";
    cout << "4. Uruchom algorytm Prima                       \n";
    cout << "5. Uruchom algorytm Kruskala                    \n";
    cout << "6. Uruchom algorytm Dijkstry                    \n";
    cout << "7. Uruchom algorytm Forda-Bellmana              \n";
    cout << "8. Wyjscie do wyboru trybu pracy                \n";
    cout << "Wpisz numer zadania:";
    cin >> task;
    return task;
}

int Menu::displaySimulationMenu() { // Implementacja wyswietlania menu dla trybu badawczego
    int task;
    cout << "---------------------------------- \n";
    cout << "      --- Simulation Menu ---      \n";
    cout << "1. Wybor algorytmu                 \n";
    cout << "2. Wyjscie do wyboru trybu pracy   \n";
    cout << "Wpisz numer zadania:";
    cin >> task;
    return task;
}

int Menu::displayAlgorithmMenu() { // Implementacja wyswietlania menu do wyboru algorytmu
    int task;
    cout << "------------------------------------------------\n";
    cout << "           --- Algorithm Menu ---               \n";
    cout << "1. Uruchom algorytm Prima - macierz             \n";
    cout << "2. Uruchom algorytm Prima - lista               \n";
    cout << "3. Uruchom algorytm Kruskala - macierz          \n";
    cout << "4. Uruchom algorytm Kruskala - lista            \n";
    cout << "5. Uruchom algorytm Dijkstry - macierz          \n";
    cout << "6. Uruchom algorytm Dijkstry - lista            \n";
    cout << "7. Uruchom algorytm Forda-Bellmana - macierz    \n";
    cout << "8. Uruchom algorytm Forda-Bellmana - lista      \n";
    cout << "Wpisz numer zadania:";
    cin >> task;
    return task;
}