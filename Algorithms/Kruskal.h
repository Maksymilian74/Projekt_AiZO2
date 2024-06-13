/*
 * Klasa Kruskal odpowiedzialna jest za
 * implementacje algorytmu Kruskala
 * dla reprezentacji macierzy incydencji i listy sasiedztwa
 */

#ifndef KRUSKAL_H
#define KRUSKAL_H

#include "../Structures/IncidenceMatrix.h"
#include "../Structures/AdjacencyList.h"
#include "../Structures/MinHeap.h"

class Kruskal {
public:
    // Metoda odpowiedzialna za uruchumienie algorytmu dla macierzy incydencji
    static void runIncidenceMatrix(const IncidenceMatrix &graph);

    // Metoda odpowiedzialna za uruchumienie algorytmu dla listy sasiedztwa
    static void runAdjacencyList(const AdjacencyList &graph);

private:
    // Metoda odpowiedzialna za znalezienie zestawu elementu i zastosowanie sciezkowej kompresji
    static int find(int parent[], int i);

    // Metoda pomocnicza do polaczenia dwoch zestawow x i y
    static void unionSets(int parent[], int rank[], int x, int y);

    // Metoda pomocnicza do obslugi kolejki
    static void processEdgesWithHeap(int edges[][3], int edgeCount, int vertices);
};

#endif
