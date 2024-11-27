#include "Algoritmos.h"
#include <iostream>
#include <vector>
#include <chrono> // Para usar chrono

int main() {
    char types[] = {'r', 'c', 'd'};
    int sizes[] = {10, 100, 1000, 10000, 100000, 1000000};
    std::string algorithmNames[] = {"InsertionSort", "SelectionSort", "BubbleSort", "ShellSort", "MergeSort"};
    Algoritmos* sorters[] = {new InsertionSort(), new SelectionSort(), new BubbleSort(), new ShellSort(), new MergeSort()};

    for (int algoIndex = 0; algoIndex < 5; algoIndex++) {
        Algoritmos* sorter = sorters[algoIndex];
        std::string algorithmName = algorithmNames[algoIndex];

        for (char type : types) {
            std::string route;
            for (int size : sizes) {
                std::vector<int> data;
                if (type == 'r') {
                    route = "Random";
                    data = sorter->generateRandomData(size);
                } else if (type == 'c') {
                    route = "Crescente";
                    data = sorter->generateSortedData(size);
                } else if (type == 'd') {
                    route = "Decrescente";
                    data = sorter->generateReverseSortedData(size);
                }

                sorter->saveToFile(data, "./" + algorithmName + "/ArquivosEntrada/" + route + "/input_" + std::to_string(size) + ".txt", size);
                sorter->createDirectories(algorithmName);

                std::cout << "Ordenando (" << route << ", tamanho " << size << ") com " << algorithmName << "...\n";
                std::cout.flush();

                auto start = std::chrono::high_resolution_clock::now();
                sorter->sortAndMeasureTime(data);
                auto end = std::chrono::high_resolution_clock::now();

                double timeTaken = std::chrono::duration<double, std::milli>(end - start).count();

                double timeInSeconds = timeTaken / 1000.0;

                sorter->saveToFile(data, "./" + algorithmName + "/ArquivosSaida/" + route + "/output_sorted_" + std::to_string(size) + ".txt", size);
                sorter->saveTimeToFile(timeInSeconds, "./" + algorithmName + "/ArquivoTempo/" + route + "/output_time_" + std::to_string(size) + ".txt");

                std::cout << "Ordenacao (" << route << ", tamanho " << size << ") concluida. Resultados salvos.\n";
                std::cout << "Tempo de execucao: " << timeInSeconds << " segundos\n";
            }
        }

        delete sorter; 
    }

    return 0;
}
