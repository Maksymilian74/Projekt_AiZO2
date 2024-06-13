/*
 * Klasa MinHeap odpowiedzialna jest za
 * implementacje kopca minimalnego
 *
 */

#ifndef MINHEAP_H
#define MINHEAP_H

class MinHeap {
private:
    int** heapArray; // Tablica przechowujaca elementy kopca
    int capacity;    // Maksymalna pojemnosc kopca
    int heapSize;    // Aktualna liczba elementow w kopcu

    // Pomocnicza funkcja do utrzymania wlasnosci kopca minimalnego
    void heapify(int idx);

public:
    // Konstruktor
    MinHeap(int capacity);

    // Destruktor
    ~MinHeap();

    // Metoda do wstawiania nowego elementu do kopca
    void insertKey(int u, int v, int weight);

    // Metoda do usuwania i zwracania najmniejszego elementu z kopca
    int* extractMin();

    // Metoda sprawdzajaca, czy kopiec jest pusty
    bool isEmpty() const;

    // Metoda do zmniejszania klucza elementu o indeksie u
    void decreaseKey(int u, int new_weight);
};

#endif
