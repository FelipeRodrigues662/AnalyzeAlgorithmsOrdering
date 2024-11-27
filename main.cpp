#include "Algoritmos.h"
#include <iostream>
#include <vector>

int main() {
    int choice;
    char type;
    int size;
    std::string algorithmName;
    std::string route;

    do {
        
        do{
            std::cout << "Escolha uma opcao:\n";
            std::cout << "1. Insertion Sort\n";
            std::cout << "2. Selection Sort\n";
            std::cout << "3. Bubble Sort\n";
            std::cout << "4. Shell Sort\n";
            std::cout << "5. Merge Sort\n";
            std::cout << "0. Sair\n";
            std::cin >> choice;

            if (choice == 0) break;

        } while(choice > 5);

        system("cls");

        do{
            std::cout << "Escolha o tipo de dados:\n";
            std::cout << "'r' para randomico\n";
            std::cout << "'c' para crescente\n";
            std::cout << "'d' para decrescente\n";
            std::cin >> type;

            if(type == 'r' || type == 'c' || type == 'd')
                break;
            std::cout << "Tipo invalido. Tente novamente: ";

        } while (true);
        
        system("cls");

        do{
            std::cout << "Escolha o tamanho (10, 100, 1000, 10000, 100000, 1000000):\n";
            std::cin >> size;

            if(size == 10 || size == 100 || size == 1000 || size == 10000 || size == 100000 || size == 1000000)
                    break;
                std::cout << "Tamanho invalido. Tente novamente: ";

        } while (true);

        system("cls");

        std::vector<int> data;
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
        } else if (choice == 5) {
            sorter = new MergeSort();
            algorithmName = "MergeSort";
        } 

        if (type == 'r') {
            data = sorter->generateRandomData(size);
            route = "Random";
        } else if (type == 'c') {
            data = sorter->generateSortedData(size);
            route = "Crescente";
        } else if (type == 'd') {
            data = sorter->generateReverseSortedData(size);
            route = "Decrescente";
        } 
        
        sorter->createDirectories(algorithmName);

        sorter->saveToFile(data, "./" + algorithmName + "/ArquivosEntrada/" + route + "/input_" + std::to_string(size) + ".txt", size);

        double timeTaken = sorter->sortAndMeasureTime(data);
        timeTaken = timeTaken / 1000;


        sorter->saveToFile(data, "./" + algorithmName + "/ArquivosSaida/" + route + "/output_sorted_" + std::to_string(size) + ".txt", size);
        sorter->saveTimeToFile(timeTaken, "./" + algorithmName + "/ArquivoTempo/" + route + "/output_time_" + std::to_string(size) + ".txt");

        std::cout << "Ordenacao concluida. Resultados salvos.\n";
        std::cout << "Tempo de execucao: " << timeTaken << " s\n";

       
        delete sorter;

    } while (choice != 0);

    return 0;
}
