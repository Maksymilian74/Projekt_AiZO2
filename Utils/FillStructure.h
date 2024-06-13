/*
 * Klasa FillStructure odpowiedzialna jest za
 * implementacje generowania losowego grafu
 * o zadaniej liczbie wierzcholkow i gestosci
 */

#ifndef FILLSTRUCTURE_H
#define FILLSTRUCTURE_H

#include "../Structures/IncidenceMatrix.h"
#include "../Structures/AdjacencyList.h"

class FillStructure {
public:
    // Metoda odpowiedzialna za generowanie losowego grafu
    static void generateRandomGraph(IncidenceMatrix &matrix, AdjacencyList &directedList, AdjacencyList &undirectedList, int vertices, int density);
};

#endif

