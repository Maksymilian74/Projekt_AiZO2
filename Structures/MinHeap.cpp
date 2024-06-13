#include "MinHeap.h"
#include <iostream>

using namespace std;

// Konstruktor
MinHeap::MinHeap(int capacity) : capacity(capacity), heapSize(0) {
    heapArray = new int*[capacity];
    for (int i = 0; i < capacity; ++i) {
        heapArray[i] = new int[3];
    }
}

// Destruktor
MinHeap::~MinHeap() {
    for (int i = 0; i < heapSize; ++i) {
        delete[] heapArray[i];
    }
    delete[] heapArray;
}

// Metoda odpowiedzialna za dodanie klucza do kopca
void MinHeap::insertKey(int u, int v, int weight) {
    if (heapSize == capacity) {
        cout << "Przepelnienie kopca!" << endl;
        return;
    }

    // wstawianie klucza na koniec
    int i = heapSize++;
    heapArray[i][0] = u;
    heapArray[i][1] = v;
    heapArray[i][2] = weight;

    // naprawa kopca
    while (i != 0 && heapArray[i][2] < heapArray[(i - 1) / 2][2]) {
        swap(heapArray[i], heapArray[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Metoda odpowiedzialna za wyciagniecie minimum
int* MinHeap::extractMin() {
    if (heapSize <= 0) {
        return nullptr;
    }
    if (heapSize == 1) {
        --heapSize;
        return heapArray[0];
    }

    // przechowanie najmniejszej wartosci i usuniecie z kopca
    int* root = heapArray[0];
    heapArray[0] = heapArray[--heapSize];
    heapify(0);

    return root;
}

// Metoda pomocnicza do naprawy kopca
void MinHeap::heapify(int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heapSize && heapArray[left][2] < heapArray[smallest][2]) {
        smallest = left;
    }
    if (right < heapSize && heapArray[right][2] < heapArray[smallest][2]) {
        smallest = right;
    }
    if (smallest != idx) {
        swap(heapArray[idx], heapArray[smallest]);
        heapify(smallest);
    }
}

// Metoda odpowiedzialna za sprawdzenie czy kopiec jest pusty
bool MinHeap::isEmpty() const {
    return heapSize == 0;
}

// Metoda odpowiedzialna za zmniejszenie wagi
void MinHeap::decreaseKey(int u, int new_weight) {
    int i;
    for (i = 0; i < heapSize; ++i) {
        if (heapArray[i][0] == u) {
            heapArray[i][2] = new_weight;
            break;
        }
    }
    while (i != 0 && heapArray[i][2] < heapArray[(i - 1) / 2][2]) {
        swap(heapArray[i], heapArray[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}
