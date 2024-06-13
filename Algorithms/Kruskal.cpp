#include "Kruskal.h"
#include <iostream>
#include <cmath>

using namespace std;

// Metoda pomocnicza do znalezienia zestawu elementu i zastosowanie sciezkowej kompresji
int Kruskal::find(int parent[], int i) {
    if (parent[i] != i)
        parent[i] = find(parent, parent[i]);
    return parent[i];
}

// Metoda pomocnicza do polaczenia dwoch zestawow x i y
void Kruskal::unionSets(int parent[], int rank[], int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);

    if (rank[rootX] < rank[rootY])
        parent[rootX] = rootY;
    else if (rank[rootX] > rank[rootY])
        parent[rootY] = rootX;
    else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}

// Metoda pomocnicza do obslugi kolejki
void Kruskal::processEdgesWithHeap(int edges[][3], int edgeCount, int vertices) {
    MinHeap minHeap(edgeCount);

    for (int i = 0; i < edgeCount; ++i) {
        minHeap.insertKey(edges[i][0], edges[i][1], edges[i][2]);
    }

    int* parent = new int[vertices];
    int* rank = new int[vertices];

    for (int i = 0; i < vertices; ++i) {
        parent[i] = i;
        rank[i] = 0;
    }

  //  cout << "Krawedz \tWaga\n";
    while (!minHeap.isEmpty()) {
        int* minEdge = minHeap.extractMin();
        int x = find(parent, minEdge[0]);
        int y = find(parent, minEdge[1]);

        if (x != y) {
          //  cout << minEdge[0] << " - " << minEdge[1] << "\t" << minEdge[2] << "\n";
            unionSets(parent, rank, x, y);
        }
    }

    delete[] parent;
    delete[] rank;
}

// Algorytm Kruskala dla macierzy incydencji
void Kruskal::runIncidenceMatrix(const IncidenceMatrix &graph) {
    int vertices = graph.getVertices();
    int edges = graph.getEdges();
    const int** edgeList = graph.getEdgeList();

    // Tworzenie tablicy krawedzi
    int (*edgesArray)[3] = new int[edges][3];
    for (int i = 0; i < edges; ++i) {
        edgesArray[i][0] = edgeList[i][0];
        edgesArray[i][1] = edgeList[i][1];
        edgesArray[i][2] = abs(edgeList[i][2]);
    }
    processEdgesWithHeap(edgesArray, edges, vertices);

    delete[] edgesArray;
}

// Algorytm Kruskala dla listy sasiedztwa
void Kruskal::runAdjacencyList(const AdjacencyList &graph) {
    int vertices = graph.getVertices();
    int edges = 0;
    AdjacencyList::Node** adjList = graph.getAdjacencyList();

    // Zliczanie liczby krawedzi
    for (int u = 0; u < vertices; ++u) {
        AdjacencyList::Node* node = adjList[u];
        while (node != nullptr) {
            edges++;
            node = node->next;
        }
    }

    // Tworzenie tablicy krawedzi
    int (*edgesArray)[3] = new int[edges][3];
    int index = 0;
    for (int u = 0; u < vertices; ++u) {
        AdjacencyList::Node* node = adjList[u];
        while (node != nullptr) {
            edgesArray[index][0] = u;
            edgesArray[index][1] = node->edge.to;
            edgesArray[index][2] = node->edge.weight;
            index++;
            node = node->next;
        }
    }

    processEdgesWithHeap(edgesArray, edges, vertices);

    delete[] edgesArray;
}
