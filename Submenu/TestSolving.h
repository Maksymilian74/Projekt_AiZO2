/*
 * Klasa TestSolving odpowiedzialna jest za
 * implementacje podmenu do testowania algorytmow
 * oraz struktur danych
 */

#ifndef PROJEKT2_AIZO_TESTSOLVING_H
#define PROJEKT2_AIZO_TESTSOLVING_H

#include <chrono>
#include <string>
#include "../Structures/IncidenceMatrix.h"
#include "../Structures/AdjacencyList.h"

using namespace std;

class TestSolving {
public:
    // Konstruktor
    TestSolving();

    // Destruktor
    ~TestSolving();

    // Metoda odpowiedzialna za wczytanie danych z pliku
    void loadDataFromFile(string fileToOpen);

    // Metoda odpowiedzialna za generowanie grafu
    void generateRandomGraph(int vertices, int density);

    // Metoda odpowiedzialna za wyswietlenie grafu
    void displayGraph();

    // Metoda uruchamiajaca algorytm Prima
    void algorithmPrim();

    // Metoda uruchamiajaca algorytm Kruskala
    void algorithmKruskal();

    // Metoda uruchamiajaca algorytm Dijkstry
    void algorithmDijkstra();

    // Metoda uruchamiajaca algorytm Forda-Bellmana
    void algorithmFordBellman();

private:
    IncidenceMatrix* incidenceMatrix; // Wskaznik na macierz incydencji
    AdjacencyList* adjacencyDirectedList;     // Wskaznik na liste sasiedztwa
    AdjacencyList* adjacencyUndirectedList;     // Wskaznik na liste sasiedztwa

    int* parent; // Tablica rodzicow w drzewie rozpinajacym
    int* key; // Tablica kluczy dla wierzcholkow w drzewie rozpinajacym
};

#endif
