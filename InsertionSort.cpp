#include "Algoritmos.h"

void InsertionSort::sort(std::vector<int>& arr) {
    for (size_t j = 1; j < arr.size(); j++) {
        int chave = arr[j];
        size_t i = j - 1;

        while (i < arr.size() && arr[i] > chave) {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = chave;
    }
}
