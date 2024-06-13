#include "SimulationSolving.h"
#include "../Algorithms/Prim.h"
#include "../Algorithms/Kruskal.h"
#include "../Algorithms/Dijkstra.h"
#include "../Algorithms/BellmanFord.h"
#include "../Utils/FillStructure.h"
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Konstruktor
SimulationSolving::SimulationSolving() {
    incidenceMatrix = nullptr;
    adjacencyDirectedList = nullptr;
    adjacencyUndirectedList = nullptr;
    time = 0;
    parent = nullptr;
    key = nullptr;
}

// Destruktor
SimulationSolving::~SimulationSolving() {
    delete incidenceMatrix;
    delete adjacencyDirectedList;
    delete adjacencyUndirectedList;
    delete[] parent;
    delete[] key;
}

// Metoda do testowania konkretnego algorytmu
void SimulationSolving::testAlgorithm(int algorithmType) {
    int verticesArray[] = {10, 20, 40, 80, 160, 320, 640};
    int densityArray[] = {25, 50, 99};
    int iterations = 20;

    for (int density : densityArray) {
        switch (density) {
            case 25:
                cout << "\nGestosc: 25%\n";
                break;
            case 50:
                cout << "\nGestosc: 50%\n";
                break;
            case 99:
                cout << "\nGestosc: 99%\n";
                break;
            default:
                cout << "Nieprawidlowa gestosc!\n";
                break;
        }

        for (int vertices : verticesArray) {
            cout << "\nWierzcholek: " << vertices << endl;

            time = 0;
            for (int i = 0; i < iterations; i++) {
                generateRandomGraph(vertices, density);
                time += runAlgorithm(algorithmType, vertices);
            }
            cout << "Algorytm " << algorithmType << " Sredni czas: " << time / iterations << " ms\n";
        }
    }
}

// Metoda do uruchamiania konkretnego algorytmu i mierzenia jego czasu wykonania
double SimulationSolving::runAlgorithm(int algorithmType, int vertices) {
    double timeIteration = 0;
    switch (algorithmType) {
        case 1:
            start = high_resolution_clock::now();
            Prim::runIncidenceMatrix(*incidenceMatrix, parent, key);
            stop = high_resolution_clock::now();
            break;
        case 2:
            start = high_resolution_clock::now();
            Prim::runAdjacencyList(*adjacencyUndirectedList, parent, key);
            stop = high_resolution_clock::now();
            break;
        case 3:
            start = high_resolution_clock::now();
            Kruskal::runIncidenceMatrix(*incidenceMatrix);
            stop = high_resolution_clock::now();
            break;
        case 4:
            start = high_resolution_clock::now();
            Kruskal::runAdjacencyList(*adjacencyUndirectedList);
            stop = high_resolution_clock::now();
            break;
        case 5:
            start = high_resolution_clock::now();
            Dijkstra::runIncidenceMatrix(*incidenceMatrix, 0, vertices - 1); // Example: from vertex 0 to vertex (vertices - 1)
            stop = high_resolution_clock::now();
            break;
        case 6:
            start = high_resolution_clock::now();
            Dijkstra::runAdjacencyList(*adjacencyDirectedList, 0, vertices - 1); // Example: from vertex 0 to vertex (vertices - 1)
            stop = high_resolution_clock::now();
            break;
        case 7:
            start = high_resolution_clock::now();
            BellmanFord::runIncidenceMatrix(*incidenceMatrix, 0, vertices - 1); // Example: from vertex 0 to vertex (vertices - 1)
            stop = high_resolution_clock::now();
            break;
        case 8:
            start = high_resolution_clock::now();
            BellmanFord::runAdjacencyList(*adjacencyDirectedList, 0, vertices - 1); // Example: from vertex 0 to vertex (vertices - 1)
            stop = high_resolution_clock::now();
            break;
        default:
            cout << "Nieznany algorytm!\n";
            break;
    }

    timeIteration = duration_cast<duration<double, milli>>(stop - start).count();
    return timeIteration;
}

// Metoda do generowania losowego grafu
void SimulationSolving::generateRandomGraph(int vertices, int density) {
    // Usuwanie istniejacej macierzy, jesli istnieje
    if (incidenceMatrix != nullptr) {
        delete incidenceMatrix;
        incidenceMatrix = nullptr;
    }

    // Usuwanie istniejacej listy sasiedztwa dla grafu skierowanego, jesli istnieje
    if (adjacencyDirectedList != nullptr) {
        delete adjacencyDirectedList;
        adjacencyDirectedList = nullptr;
    }

    // Usuwanie istniejacej listy sasiedztwa dla grafu nieskierowanego, jesli istnieje
    if (adjacencyUndirectedList != nullptr) {
        delete adjacencyUndirectedList;
        adjacencyUndirectedList = nullptr;
    }

    incidenceMatrix = new IncidenceMatrix(vertices, (density * vertices * (vertices - 1)) / 200); // maksymalna ilosc krawedzi
    adjacencyDirectedList = new AdjacencyList(vertices);
    adjacencyUndirectedList = new AdjacencyList(vertices);

    FillStructure::generateRandomGraph(*incidenceMatrix, *adjacencyDirectedList, *adjacencyUndirectedList, vertices, density);

    // Alokacja pamięci dla parent i key
    if (parent != nullptr) {
        delete[] parent;
    }
    if (key != nullptr) {
        delete[] key;
    }
    parent = new int[vertices];
    key = new int[vertices];
}
