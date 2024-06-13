/*
 * Klasa BellmanFord odpowiedzialna jest za
 * implementacje algorytmu Bellmana-Forda
 * dla reprezentacji macierzy incydencji i listy sasiedztwa
 */

#ifndef BELLMANFORD_H
#define BELLMANFORD_H

#include "../Structures/IncidenceMatrix.h"
#include "../Structures/AdjacencyList.h"

class BellmanFord {
public:
    // Metoda odpowiedzialna za uruchumienie algorytmu dla macierzy incydencji
    static void runIncidenceMatrix(const IncidenceMatrix &graph, int startVertex, int endVertex);

    // Metoda odpowiedzialna za uruchumienie algorytmu dla listy sasiedztwa
    static void runAdjacencyList(const AdjacencyList &graph, int startVertex, int endVertex);

private:
    // Metoda odpowiedzialna za wyswietlenie sciezki
    static void printPath(int parent[], int vertex);
};

#endif
