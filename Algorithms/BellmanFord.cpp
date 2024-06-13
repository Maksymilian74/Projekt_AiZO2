#include "BellmanFord.h"
#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

// Metoda pomocnicza do wydrukowania sciezki
void BellmanFord::printPath(int parent[], int vertex) {
    if (parent[vertex] == -1) {
        return;
    }

    printPath(parent, parent[vertex]);
    cout << vertex << " ";
}

// Algorytm BellmanaForda dla macierzy incydencji
void BellmanFord::runIncidenceMatrix(const IncidenceMatrix &graph, int startVertex, int endVertex) {
    int vertices = graph.getVertices();
    int edges = graph.getEdges();
    const int** matrix = graph.getMatrix();

    int* dist = new int[vertices];
    int* parent = new int[vertices];

    for (int i = 0; i < vertices; i++) {
        dist[i] = numeric_limits<int>::max();
        parent[i] = -1;
    }

    dist[startVertex] = 0;

    // Relaksacja wszystkich krawędzi |V| - 1 razy
    for (int i = 1; i <= vertices - 1; i++) {
        for (int u = 0; u < vertices; u++) {
            for (int e = 0; e < edges; e++) {
                if (matrix[u][e] != 0) {
                    int v = -1;
                    for (int k = 0; k < vertices; k++) {
                        if (matrix[k][e] == -matrix[u][e]) {
                            v = k;
                            break;
                        }
                    }
                    if (v != -1 && dist[u] != numeric_limits<int>::max() && dist[u] + abs(matrix[u][e]) < dist[v]) {
                        dist[v] = dist[u] + abs(matrix[u][e]);
                        parent[v] = u;
                    }
                }
            }
        }
    }

    // Sprawdzenie cykli o ujemnych wagach
    for (int u = 0; u < vertices; u++) {
        for (int e = 0; e < edges; e++) {
            if (matrix[u][e] != 0) {
                int v = -1;
                for (int k = 0; k < vertices; k++) {
                    if (matrix[k][e] == -matrix[u][e]) {
                        v = k;
                        break;
                    }
                }
                if (v != -1 && dist[u] != numeric_limits<int>::max() && dist[u] + abs(matrix[u][e]) < dist[v]) {
                    cout << "Graf zawiera cykle ujemne" << endl;
                    delete[] dist;
                    delete[] parent;
                    return;
                }
            }
        }
    }

    cout << "Wierzcholek\t Odleglosc\tSciezka";
    if (dist[endVertex] != numeric_limits<int>::max()) {
        cout << "\n" << startVertex << " -> " << endVertex << " \t\t " << dist[endVertex] << "\t\t" << startVertex << " ";
        printPath(parent, endVertex);
    } else {
        cout << "\nBrak sciezki " << startVertex << " do " << endVertex;
    }
    cout << endl;

    delete[] dist;
    delete[] parent;
}

// Algorytm BellmanaForda dla listy sasiedztwa
void BellmanFord::runAdjacencyList(const AdjacencyList &graph, int startVertex, int endVertex) {
    int vertices = graph.getVertices();
    AdjacencyList::Node** adjList = graph.getAdjacencyList();

    int* dist = new int[vertices];
    int* parent = new int[vertices];

    for (int i = 0; i < vertices; i++) {
        dist[i] = numeric_limits<int>::max();
        parent[i] = -1;
    }

    dist[startVertex] = 0;

    // Relaksacja wszystkich krawędzi |V| - 1 razy
    for (int i = 1; i <= vertices - 1; i++) {
        for (int u = 0; u < vertices; u++) {
            AdjacencyList::Node* node = adjList[u];
            while (node != nullptr) {
                int v = node->edge.to;
                int weight = node->edge.weight;
                if (dist[u] != numeric_limits<int>::max() && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    parent[v] = u;
                }
                node = node->next;
            }
        }
    }

    // Sprawdzenie cykli o ujemnych wagach
    for (int u = 0; u < vertices; u++) {
        AdjacencyList::Node* node = adjList[u];
        while (node != nullptr) {
            int v = node->edge.to;
            int weight = node->edge.weight;
            if (dist[u] != numeric_limits<int>::max() && dist[u] + weight < dist[v]) {
                cout << "Graf zawiera cykle ujemne" << endl;
                delete[] dist;
                delete[] parent;
                return;
            }
            node = node->next;
        }
    }

    cout << "Wierzcholek\t Odleglosc\tSciezka";
    if (dist[endVertex] != numeric_limits<int>::max()) {
        cout << "\n" << startVertex << " -> " << endVertex << " \t\t " << dist[endVertex] << "\t\t" << startVertex << " ";
        printPath(parent, endVertex);
    } else {
        cout << "\nBrak sciezki " << startVertex << " do " << endVertex;
    }
    cout << endl;

    delete[] dist;
    delete[] parent;
}
