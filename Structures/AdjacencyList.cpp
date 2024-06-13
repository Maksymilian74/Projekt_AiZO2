#include "AdjacencyList.h"
#include <iostream>

// Konstruktor
AdjacencyList::AdjacencyList(int vertices)
        : vertices(vertices), edges(0) {
    adjList = new Node*[vertices];
    for (int i = 0; i < vertices; ++i) {
        adjList[i] = nullptr;
    }
}

// Destruktor
AdjacencyList::~AdjacencyList() {
    for (int i = 0; i < vertices; ++i) {
        Node* current = adjList[i];
        while (current) {
            Node* toDelete = current;
            current = current->next;
            delete toDelete;
        }
    }
    delete[] adjList;
}

// Metoda odpowiedzialna za dodanie krawedzi do listy sasiedztwa
void AdjacencyList::addEdge(int from, int to, int weight) {
    if (from >= vertices || to >= vertices) {
        std::cerr << "Zla liczba wierzcholkow!" << std::endl;
        return;
    }

    Node* newNode = new Node;
    newNode->edge = {to, weight};
    newNode->next = adjList[from];
    adjList[from] = newNode;
    edges++;
}

// Metoda odpowiedzialna za wyswietlanie listy sasiedztwa
void AdjacencyList::display() const {
    for (int i = 0; i < vertices; ++i) {
        std::cout << "Wierzcholek " << i << ":";
        Node* current = adjList[i];
        if (current) {
            std::cout << " (" << current->edge.to << ";" << current->edge.weight << ")";
            current = current->next;
        }
        while (current) {
            std::cout << ", (" << current->edge.to << ";" << current->edge.weight << ")";
            current = current->next;
        }
        std::cout << std::endl;
    }
}

// Getter liczby wierzcholkow
int AdjacencyList::getVertices() const {
    return vertices;
}

// Getter liczby krawedzi
int AdjacencyList::getEdges() const {
    return edges;
}

// Getter listy sasiedztwa
AdjacencyList::Node** AdjacencyList::getAdjacencyList() const {
    return adjList;
}



