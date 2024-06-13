/*
 * Klasa AdjancencyList odpowiedzialna jest za
 * implementacje listy sasiedztwa
 *
 */

#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H

// Struktura przechowujaca informacje o krawedzi
struct Edge {
    int to;      // Wierzcholek docelowy
    int weight;  // Waga krawedzi
};

// Klasa reprezentujaca liste sasiedztwa grafu
class AdjacencyList {
public:
    // Struktura reprezentujaca pojedynczy wezel listy sasiedztwa
    struct Node {
        Edge edge;  // Krawedz prowadzaca do wierzcholka docelowego z waga
        Node* next; // Wskaznik do nastepnego wezla
    };

private:
    int vertices;      // Liczba wierzcholkow
    int edges;         // Liczba krawedzi
    Node** adjList;    // Tablica wskaznikow do list sasiedztwa

public:
    // Konstruktor
    AdjacencyList(int vertices);

    // Destruktor
    ~AdjacencyList();

    // Metoda dodajaca krawedz do grafu
    void addEdge(int from, int to, int weight);

    // Metoda wyswietlajaca liste sasiedztwa
    void display() const;

    // Metoda zwracajaca liczbe wierzcholkow w grafie
    int getVertices() const;

    // Metoda zwracajaca liczbe krawedzi w grafie
    int getEdges() const;

    // Metoda zwracajaca tablice wskaznikow do list sasiedztwa
    Node** getAdjacencyList() const;
};

#endif
