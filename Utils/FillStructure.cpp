#include "FillStructure.h"
#include <cstdlib>
#include <ctime>

// Metoda odpowiedzialna za generowanie losowego grafu
void FillStructure::generateRandomGraph(IncidenceMatrix &matrix, AdjacencyList &directedList, AdjacencyList &undirectedList, int vertices, int density) {
    std::srand(std::time(0));

    // Tworzenie minimalnego drzewa rozpinajacego (MST)
    for (int i = 1; i < vertices; ++i) {
        int u = i;
        int v = std::rand() % i;
        int weight = std::rand() % 100 + 1; // Losowa waga krawedzi
        matrix.addEdge(u, v, weight);
        directedList.addEdge(u, v, weight);
        undirectedList.addEdge(u, v, weight);
        undirectedList.addEdge(v, u, weight);
    }

    // Obliczenie maksymalnej liczby krawedzi
    int maxEdges = vertices * (vertices - 1) / 2;
    int requiredEdges = (density * maxEdges) / 100;

    // Dodanie pozostalych krawedzi do osiagniecia wymaganej gestosci
    int edgeCount = vertices - 1; // Bo juz mamy (vertices - 1) krawedzi w MST
    while (edgeCount < requiredEdges) {
        int u = std::rand() % vertices;
        int v = std::rand() % vertices;
        if (u != v) {
            int weight = std::rand() % 100 + 1;
            matrix.addEdge(u, v, weight);
            directedList.addEdge(u, v, weight);
            undirectedList.addEdge(u, v, weight);
            undirectedList.addEdge(v, u, weight);
            edgeCount++;
        }
    }
}

