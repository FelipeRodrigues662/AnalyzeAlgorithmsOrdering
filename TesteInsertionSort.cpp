#include "InsertionSort.h"
#include <iostream>
#include <vector>

int main() {
    InsertionSort sorter;
    sorter.createDirectories(); 


    std::vector<char> tipos = {'r', 'c', 'd'};
    std::vector<int> tamanhos = {10, 100, 1000, 10000, 100000, 1000000};
    std::string route;

    for (char type : tipos) {
        for (int size : tamanhos) {
            std::vector<int> data;

            if (type == 'r') {
                data = sorter.generateRandomData(size);
                route = "Random";
            } else if (type == 'c') {
                data = sorter.generateSortedData(size);
                route = "Crescente";
            } else if (type == 'd') {
                data = sorter.generateReverseSortedData(size);
                route = "Decrescente";
            } else {
                std::cerr << "Tipo invalido. Tente novamente.\n";
                continue;
            }

            sorter.saveToFile(data, "./InsertionSort/ArquivosEntrada/" + route + "/input_" + std::to_string(size) + ".txt", size);


            double timeTaken = sorter.sortAndMeasureTime(data);

            sorter.saveToFile(data, "./InsertionSort/ArquivosSaida/" + route + "/output_sorted_" + std::to_string(size) + ".txt", size);
            sorter.saveTimeToFile(timeTaken, "./InsertionSort/ArquivoTempo/" + route + "/output_time_" + std::to_string(size) + ".txt");

            std::cout << "Ordenacao concluida para " << route << " com tamanho " << size << ". Resultados salvos.\n";
            std::cout << "Tempo de execucao: " << timeTaken << " segundos\n";
        }
    }

    return 0;
}
