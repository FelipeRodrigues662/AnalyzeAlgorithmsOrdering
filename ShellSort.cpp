#include "Algoritmos.h"

void ShellSort::sort(std::vector<int>& arr) {
    for (size_t gap = arr.size() / 2; gap > 0; gap /= 2) {
        for (size_t i = gap; i < arr.size(); i++) {
            int temp = arr[i];
            size_t j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}
