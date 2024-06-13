/*
 * Klasa Prim odpowiedzialna jest za
 * implementacje algorytmu Prima
 * dla reprezentacji macierzy incydencji i listy sasiedztwa
 */

#ifndef PRIM_H
#define PRIM_H

#include "../Structures/IncidenceMatrix.h"
#include "../Structures/AdjacencyList.h"

class Prim {
public:
    // Metoda odpowiedzialna za uruchumienie algorytmu dla macierzy incydencji
    static void runIncidenceMatrix(const IncidenceMatrix &graph, int* &parent, int* &key);

    // Metoda odpowiedzialna za uruchumienie algorytmu dla listy sasiedztwa
    static void runAdjacencyList(const AdjacencyList &graph, int* &parent, int* &key);
};

#endif
