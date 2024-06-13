#include "Prim.h"
#include "../Structures/MinHeap.h"
#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

// Algorytm Prima dla macierzy incydencji
void Prim::runIncidenceMatrix(const IncidenceMatrix &graph, int* &parent, int* &key) {
    int vertices = graph.getVertices();
    int edges = graph.getEdges();
    const int** matrix = graph.getMatrix();

    bool* inMST = new bool[vertices];

    MinHeap minHeap(vertices);

    for (int i = 0; i < vertices; ++i) {
        key[i] = numeric_limits<int>::max();
        inMST[i] = false;
        minHeap.insertKey(i, -1, key[i]);
    }

    key[0] = 0;
    minHeap.decreaseKey(0, 0);

    while (!minHeap.isEmpty()) {
        int* minNode = minHeap.extractMin();
        int u = minNode[0];
        inMST[u] = true;

        for (int e = 0; e < edges; ++e) {
            if (matrix[u][e] != 0) {
                for (int v = 0; v < vertices; ++v) {
                    if (v != u && matrix[v][e] != 0 && !inMST[v]) {
                        int weight = abs(matrix[u][e]);
                        if (weight < key[v]) {
                            key[v] = weight;
                            parent[v] = u;
                            minHeap.decreaseKey(v, weight);
                        }
                    }
                }
            }
        }
    }

    delete[] inMST;
}

// Algorytm Prima dla listy sasiedztwa
void Prim::runAdjacencyList(const AdjacencyList &graph, int* &parent, int* &key) {
    int vertices = graph.getVertices();
    AdjacencyList::Node** adjList = graph.getAdjacencyList();

    bool* inMST = new bool[vertices];

    MinHeap minHeap(vertices);

    for (int i = 0; i < vertices; ++i) {
        key[i] = numeric_limits<int>::max();
        inMST[i] = false;
        minHeap.insertKey(i, -1, key[i]);
    }

    key[0] = 0;
    minHeap.decreaseKey(0, 0);

    while (!minHeap.isEmpty()) {
        int* minNode = minHeap.extractMin();
        int u = minNode[0];
        inMST[u] = true;

        AdjacencyList::Node* node = adjList[u];
        while (node != nullptr) {
            int v = node->edge.to;
            int weight = node->edge.weight;
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                minHeap.decreaseKey(v, weight);
            }
            node = node->next;
        }
    }
    delete[] inMST;
}
