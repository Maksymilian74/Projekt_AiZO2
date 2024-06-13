#include "TestSolving.h"
#include "../Utils/FillStructure.h"
#include "../Algorithms/Prim.h"
#include "../Algorithms/Kruskal.h"
#include "../Algorithms/Dijkstra.h"
#include "../Algorithms/BellmanFord.h"
#include <iostream>
#include <fstream>

using namespace std;
using namespace std::chrono;

// Konstruktor
TestSolving::TestSolving() {
    incidenceMatrix = nullptr;
    adjacencyDirectedList = nullptr;
    adjacencyUndirectedList = nullptr;
    parent = nullptr;
    key = nullptr;
}

// Destruktor
TestSolving::~TestSolving() {
    delete incidenceMatrix;
    delete adjacencyDirectedList;
    delete adjacencyUndirectedList;
    delete[] parent;
    delete[] key;
}

// Metoda odpowiedzialna za wczytanie danych z pliku do tablicy
void TestSolving::loadDataFromFile(string fileToOpen) {
    ifstream file(fileToOpen); // Tworzenie strumienia do odczytu danych z pliku
    if (!file.is_open()) {
        cout << "-------------------------------------------\n";
        cout << "Blad! Nie udalo sie otworzyc pliku.\n";
        return;
    }

    int numEdges, numVertices;
    file >> numEdges >> numVertices; // Wczytanie liczby krawędzi i wierzchołków

    // Usuwanie istniejącej macierzy, jesli istnieje
    if (incidenceMatrix != nullptr) {
        delete incidenceMatrix;
        incidenceMatrix = nullptr;
    }

    // Tworzenie instancji listy sasiedztwa dla grafu skierowanego
    if (adjacencyDirectedList != nullptr) {
        delete adjacencyDirectedList;
        adjacencyDirectedList = nullptr;
    }

    // Tworzenie instancji listy sasiedztwa dla grafu nieskierowanego
    if (adjacencyUndirectedList != nullptr) {
        delete adjacencyUndirectedList;
        adjacencyUndirectedList = nullptr;
    }

    // Tworzenie instancji macierzy incydencji
    incidenceMatrix = new IncidenceMatrix(numVertices, numEdges);

    // Tworzenie instancji listy sasiedztwa dla grafu skierowanego
    adjacencyDirectedList = new AdjacencyList(numVertices);

    // Tworzenie instancji listy sasiedztwa dla grafu nieskierowanego
    adjacencyUndirectedList = new AdjacencyList(numVertices);

    int startVertex, endVertex, weight;
    // Wczytywanie danych o krawedziach i dodawanie ich do macierzy incydencji
    for (int i = 0; i < numEdges; ++i) {
        file >> startVertex >> endVertex >> weight;
        std::cout << "Wpisywanie" << std::endl;
        incidenceMatrix->addEdge(startVertex, endVertex, weight);
        adjacencyDirectedList->addEdge(startVertex, endVertex, weight);
        adjacencyUndirectedList->addEdge(startVertex, endVertex, weight);
        adjacencyUndirectedList->addEdge(endVertex, startVertex, weight);
    }

    file.close();
}

// Metoda odpowiedzialna za wygenerowanie grafu
void TestSolving::generateRandomGraph(int vertices, int density) {
    // Usuwanie istniejacej macierzy, jesli istnieje
    if (incidenceMatrix != nullptr) {
        delete incidenceMatrix;
        incidenceMatrix = nullptr;
    }

    // Usuwanie istniejącej listy sasiedztwa dla grafu skierowanego, jesli istnieje
    if (adjacencyDirectedList != nullptr) {
        delete adjacencyDirectedList;
        adjacencyDirectedList = nullptr;
    }

    // Usuwanie istniejącej listy sasiedztwa dla grafu nieskierowanego, jesli istnieje
    if (adjacencyUndirectedList != nullptr) {
        delete adjacencyUndirectedList;
        adjacencyUndirectedList = nullptr;
    }

    // Obliczenie liczby krawedzi na podstawie gestosci
    int maxEdges = vertices * (vertices - 1) / 2;
    int numEdges = (density * maxEdges) / 100;

    // Tworzenie instancji macierzy incydencji
    incidenceMatrix = new IncidenceMatrix(vertices, numEdges);

    // Tworzenie instancji listy sasiedztwa dla grafu skierowanego
    adjacencyDirectedList = new AdjacencyList(vertices);

    // Tworzenie instancji listy sasiedztwa dla grafu nieskierowanego
    adjacencyUndirectedList = new AdjacencyList(vertices);

    // Wygenerowanie losowego grafu za pomocą metody z klasy FillStructure
    FillStructure::generateRandomGraph(*incidenceMatrix, *adjacencyDirectedList, *adjacencyUndirectedList, vertices, density);
}

// Metoda odpowiedzialna za wyswietlenie grafu
void TestSolving::displayGraph() {
    if (incidenceMatrix != nullptr) {
        std::cout << std::endl << "Macierz incydencji:" << std::endl;
        incidenceMatrix->display();
    }  else {
        std::cout << "Brak macierzy." << std::endl;
    }

    if (adjacencyDirectedList != nullptr) {
        std::cout << std::endl << "Lista sasiedztwa dla grafu skierowanego:" << std::endl;
        adjacencyDirectedList->display();
    } else {
        std::cout << "Brak listy." << std::endl;
    }

    if (adjacencyUndirectedList != nullptr) {
        std::cout << std::endl << "Lista sasiedztwa dla grafu nieskierowanego:" << std::endl;
        adjacencyUndirectedList->display();
    } else {
        std::cout << "Brak listy" << std::endl;
    }
}

// Metoda odpowiedzialna za uruchomienie algorytmu Prima
void TestSolving::algorithmPrim() {
    int vertices = incidenceMatrix->getVertices();

    delete[] parent;
    delete[] key;
    parent = new int[vertices];
    key = new int[vertices];

    if (incidenceMatrix != nullptr) {
        cout << "Algorytm Prima dla macierzy incydencji:" << endl;
        Prim::runIncidenceMatrix(*incidenceMatrix, parent, key);
        cout << "Krawedz \tWaga\n";
        for (int i = 1; i < incidenceMatrix->getVertices(); ++i) {
            cout << parent[i] << " - " << i << "\t" << key[i] << "\n";
        }
    } else {
        cout << "Brak macierzy" << endl;
    }

    if (adjacencyUndirectedList != nullptr) {
        cout << "Algorytm Prima dla listy sasiedztwa:" << endl;
        Prim::runAdjacencyList(*adjacencyUndirectedList, parent, key);
        cout << "Krawedz \tWaga\n";
        for (int i = 1; i < adjacencyUndirectedList->getVertices(); ++i) {
            cout << parent[i] << " - " << i << "\t" << key[i] << "\n";
        }
    } else {
        cout << "Brak listy" << endl;
    }

    delete[] parent;
    delete[] key;
    parent = nullptr;
    key = nullptr;
}

// Metoda odpowiedzialna za uruchomienie algorytmu Kruskala
void TestSolving::algorithmKruskal() {
    if (incidenceMatrix != nullptr) {
        cout << "Algorytm Kruskala dla macierzy incydencji:" << endl;
        Kruskal::runIncidenceMatrix(*incidenceMatrix);
        cout << "Krawedz \tWaga\n";
    } else {
        cout << "Brak macierzy\n" << endl;
    }

    if (adjacencyUndirectedList != nullptr) {
        cout << "Algorytm Kruskala dla listy sasiedztwa:" << endl;
        Kruskal::runAdjacencyList(*adjacencyUndirectedList);
    } else {
        cout << "Brak listy." << endl;
    }
}

// Metoda odpowiedzialna za uruchomienie algorytmu Dijkstry
void TestSolving::algorithmDijkstra() {
    int startVertex, endVertex;
    cout << "Krawedz startowa: ";
    cin >> startVertex;
    cout << "Krawedz koncowa: ";
    cin >> endVertex;

    if (incidenceMatrix != nullptr) {
        cout << "Algorytm Dijkstry dla macierzy incydencji:" << endl;
        Dijkstra::runIncidenceMatrix(*incidenceMatrix, startVertex, endVertex);
    } else {
        cout << "Brak macierzy" << endl;
    }

    if (adjacencyDirectedList != nullptr) {
        cout << "Algorytm Dijkstry dla listy sasiedztwa:" << endl;
        Dijkstra::runAdjacencyList(*adjacencyDirectedList, startVertex, endVertex);
    } else {
        cout << "Brak listy" << endl;
    }
}

// Metoda odpowiedzialna za uruchomienie algorytmu Bellmana-Forda
void TestSolving::algorithmFordBellman() {
    int startVertex, endVertex;
    cout << "Krawedz startowa: ";
    cin >> startVertex;
    cout << "Krawedz koncowa: ";
    cin >> endVertex;

    if (incidenceMatrix != nullptr) {
        cout << "Algorytm Bellmana-Forda dla macierzy incydencji:" << endl;
        BellmanFord::runIncidenceMatrix(*incidenceMatrix, startVertex, endVertex);
    } else {
        cout << "Brak macierzy" << endl;
    }

    if (adjacencyDirectedList != nullptr) {
        cout << "Algorytm Bellmana-Forda dla listy sasiedztwa:" << endl;
        BellmanFord::runAdjacencyList(*adjacencyDirectedList, startVertex, endVertex);
    } else {
        cout << "Brak listy" << endl;
    }
}
