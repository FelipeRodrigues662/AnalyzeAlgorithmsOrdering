#include "Algoritmos.h"
#include <iostream>
#include <vector>
#include <chrono> // Para usar chrono
#include <thread> // Para usar sleep_for

int main() {
    int choice;
    char types[] = {'r', 'c', 'd'};
    int sizes[] = {10, 100, 1000, 10000, 100000, 1000000};
    std::string algorithmName;

    do {
        do {
            std::cout << "Escolha uma opcao:\n";
            std::cout << "1. Insertion Sort\n";
            std::cout << "2. Selection Sort\n";
            std::cout << "3. Bubble Sort\n";
            std::cout << "4. Shell Sort\n";
            std::cout << "0. Sair\n";
            std::cin >> choice;

            if (choice == 0) break;

        } while (choice < 1 || choice > 4);

        system("cls");

        if (choice == 0) break;

        Algoritmos* sorter;
        if (choice == 1) {
            sorter = new InsertionSort();
            algorithmName = "InsertionSort";
        } else if (choice == 2) {
            sorter = new SelectionSort();
            algorithmName = "SelectionSort";
        } else if (choice == 3) {
            sorter = new BubbleSort();
            algorithmName = "BubbleSort";
        } else if (choice == 4) {
            sorter = new ShellSort();
            algorithmName = "ShellSort";
        }

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

                std::cout << "Ordenando (" << route << ", tamanho " << size << ")"; // Mensagem antes de iniciar a ordenação
                std::cout.flush();

                // Medir o tempo de ordenação
                auto start = std::chrono::high_resolution_clock::now();
                sorter->sortAndMeasureTime(data);
                auto end = std::chrono::high_resolution_clock::now();

                // Calcular o tempo total em milissegundos
                double timeTaken = std::chrono::duration<double, std::milli>(end - start).count();
                
                // Mostrar os pontos durante a ordenação
                showProcessingDots(static_cast<int>(timeTaken)); // Passa o tempo em milissegundos

                // Convertendo tempo para segundos
                double timeInSeconds = timeTaken / 1000.0;

                sorter->saveToFile(data, "./" + algorithmName + "/ArquivosSaida/" + route + "/output_sorted_" + std::to_string(size) + ".txt", size);
                sorter->saveTimeToFile(timeInSeconds, "./" + algorithmName + "/ArquivoTempo/" + route + "/output_time_" + std::to_string(size) + ".txt");

                std::cout << "\nOrdenacao (" << route << ", tamanho " << size << ") concluida. Resultados salvos.\n";
                std::cout << "Tempo de execucao: " << timeInSeconds << " segundos\n";
            }
        }

        delete sorter;

    } while (choice != 0);

    return 0;
}
