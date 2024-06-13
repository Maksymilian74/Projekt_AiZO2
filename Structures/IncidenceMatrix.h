/*
 * Klasa IncidenceMAtrix odpowiedzialna jest za
 * implementacje macierzy incydencji
 *
 */

#ifndef INCIDENCEMATRIX_H
#define INCIDENCEMATRIX_H

class IncidenceMatrix {
private:
    int vertices;    // Liczba wierzcholkow
    int edges;       // Liczba krawedzi
    int currentEdge; // Liczba krawedzi aktualnie
    int** matrix;    // Macierz incydencji
    int** edgeList;  // Lista krawedzi

public:
    // Konstruktor
    IncidenceMatrix(int vertices, int edges);

    // Destruktor
    ~IncidenceMatrix();

    // Metoda do dodawania krawedzi do macierzy incydencji
    void addEdge(int u, int v, int weight);

    // Metoda do wyswietlania macierzy incydencji
    void display() const;

    // Metoda do wyswietlania listy krawedzi
    void displayEdges() const;

    // Metoda zwracajaca liczbe wierzcholkow
    int getVertices() const;

    // Metoda zwracajaca liczbe krawedzi
    int getEdges() const;

    // Metoda zwracajaca macierz incydencji
    const int** getMatrix() const;

    // Metoda zwracajaca liste krawedzi
    const int** getEdgeList() const;
};

#endif

