/*
 * Klasa Dijkstra odpowiedzialna jest za
 * implementacje algorytmu Dijkstry
 * dla reprezentacji macierzy incydencji i listy sasiedztwa
 */

#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "../Structures/IncidenceMatrix.h"
#include "../Structures/AdjacencyList.h"

class Dijkstra {
public:
    // Metoda odpowiedzialna za uruchumienie algorytmu dla macierzy incydencji
    static void runIncidenceMatrix(const IncidenceMatrix &graph, int startVertex, int endVertex);

    // Metoda odpowiedzialna za uruchumienie algorytmu dla listy sasiedztwa
    static void runAdjacencyList(const AdjacencyList &graph, int startVertex, int endVertex);

private:
    // Metoda odpowiedzialna za wyswietlenie sciezki
    static void printPath(int parent[], int vertex);

    // Metoda odpowiedzialna za znalezienie minimalnego dystansu
    static int minDistance(int dist[], bool sptSet[], int vertices);
};

#endif
