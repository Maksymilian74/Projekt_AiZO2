#include "Dijkstra.h"
#include <iostream>
#include <limits>

using namespace std;

// Funkcja pomocnicza do znalezienia wierzcholka z minimalną odlegloscia
int Dijkstra::minDistance(int dist[], bool sptSet[], int vertices) {
    int min = numeric_limits<int>::max(), min_index;

    for (int v = 0; v < vertices; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

// Funkcja pomocnicza do wydrukowania sciezki
void Dijkstra::printPath(int parent[], int vertex) {
    if (parent[vertex] == -1)
        return;

    printPath(parent, parent[vertex]);
    cout << vertex << " ";
}

// Algorytm Dijkstry dla macierzy incydencji
void Dijkstra::runIncidenceMatrix(const IncidenceMatrix &graph, int startVertex, int endVertex) {
    int vertices = graph.getVertices();
    int edges = graph.getEdges();
    const int** matrix = graph.getMatrix();

    int* dist = new int[vertices]; // Tablica do przechowywania najkrotszych odleglosci
    bool* sptSet = new bool[vertices]; // Tablica do przechowywania wierzcholkow wlaczonych do MST
    int* parent = new int[vertices]; // Tablica do przechowywania sciezki

    for (int i = 0; i < vertices; i++) {
        dist[i] = numeric_limits<int>::max();
        sptSet[i] = false;
        parent[i] = -1;
    }

    dist[startVertex] = 0;

    for (int count = 0; count < vertices - 1; count++) {
        int u = minDistance(dist, sptSet, vertices);
        sptSet[u] = true;

        for (int e = 0; e < edges; e++) {
            if (matrix[u][e] > 0) {
                for (int v = 0; v < vertices; v++) {
                    if (matrix[v][e] == -matrix[u][e]) {
                        int weight = matrix[u][e];
                        if (!sptSet[v] && dist[u] != numeric_limits<int>::max() && dist[u] + weight < dist[v]) {
                            dist[v] = dist[u] + weight;
                            parent[v] = u;
                        }
                    }
                }
            }
        }
    }

    cout << "Wierzcholek\t Odleglosc\tSciezka";
    for (int i = 0; i < vertices; i++) {
        if (i == endVertex) {
            cout << "\n" << startVertex << " -> " << i << " \t\t " << dist[i] << "\t\t" << startVertex << " ";
            printPath(parent, i);
        }
    }
    cout << endl;

    delete[] dist;
    delete[] sptSet;
    delete[] parent;
}


// Algorytm Dijkstry dla listy sasiedztwa
void Dijkstra::runAdjacencyList(const AdjacencyList &graph, int startVertex, int endVertex) {
    int vertices = graph.getVertices();
    AdjacencyList::Node** adjList = graph.getAdjacencyList();

    int* dist = new int[vertices];
    bool* sptSet = new bool[vertices];
    int* parent = new int[vertices];

    for (int i = 0; i < vertices; i++) {
        dist[i] = numeric_limits<int>::max();
        sptSet[i] = false;
        parent[i] = -1;
    }

    dist[startVertex] = 0;

    for (int count = 0; count < vertices; count++) {
        int u = minDistance(dist, sptSet, vertices);
        sptSet[u] = true;

        AdjacencyList::Node* node = adjList[u];
        while (node != nullptr) {
            int v = node->edge.to;
            int weight = node->edge.weight;
            if (!sptSet[v] && dist[u] != numeric_limits<int>::max() && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
            }
            node = node->next;
        }
    }

    cout << "Wierzcholek\t Odleglosc\tSciezka";
    if (dist[endVertex] != numeric_limits<int>::max()) {
        cout << "\n" << startVertex << " -> " << endVertex << " \t\t " << dist[endVertex] << "\t\t" << startVertex << " ";
        printPath(parent, endVertex);
    } else {
        cout << "\nBrak sciezki z " << startVertex << " do " << endVertex;
    }
    cout << endl;

    delete[] dist;
    delete[] sptSet;
    delete[] parent;
}