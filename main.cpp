#include "InsertionSort.h"
#include <iostream>
#include <vector>

int main() {
    InsertionSort sorter;
    sorter.createDirectories(); 

    int choice;
    std::string route;
    do {
        std::cout << "Escolha uma opcao:\n";
        std::cout << "1. Insertion Sort\n";
        std::cout << "0. Sair\n";
        std::cin >> choice;

        if (choice == 1) {
            char type;
            int size;

            std::cout << "Escolha o tipo de dados:\n";
            std::cout << "'r' para randomico\n";
            std::cout << "'c' para crescente\n";
            std::cout << "'d' para decrescente\n";
            std::cin >> type;

            std::cout << "Escolha o tamanho (10, 100, 1000, 10000, 100000, 1000000):\n";
            std::cin >> size;

            std::vector<int> data;

            // Verifica o tipo escolhido e gera os dados
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
            
            // Salvar os resultados de Entrada
            sorter.saveToFile(data, "./InsertionSort/ArquivosEntrada/" + route + "/input_" + std::to_string(size) + ".txt", size);

            // Medir o tempo e ordenar os dados
            double timeTaken = sorter.sortAndMeasureTime(data);
            
            // Salvar os resultados de Saida e Tempo
            sorter.saveToFile(data, "./InsertionSort/ArquivosSaida/" + route + "/output_sorted_" + std::to_string(size) + ".txt", size);
            sorter.saveTimeToFile(timeTaken, "./InsertionSort/ArquivoTempo/" + route + "/output_time_" + std::to_string(size) + ".txt");

            std::cout << "Ordenacao concluida. Resultados salvos.\n";
            std::cout << timeTaken;
        }

    } while (choice != 0);

    return 0;
}
