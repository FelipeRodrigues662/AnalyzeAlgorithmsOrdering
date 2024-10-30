#include "InsertionSort.h"
#include <fstream>
#include <chrono>
#include <direct.h>   // Para Windows
#include <iostream>
#include <algorithm>  // Para std::generate
#include <cstdlib>    // Para std::rand e std::srand
#include <ctime>      // Para std::time
#include <sys/stat.h> // Para mkdir
#include <cerrno> // Para erro
#include <cstring> // Para strerror

void InsertionSort::createDirectoryRecursively(const std::string& path) {
    std::string::size_type pos = 0;
    while ((pos = path.find_first_of("\\/", pos)) != std::string::npos) {
        std::string subdir = path.substr(0, pos++);
        if (!subdir.empty()) {
            if (_mkdir(subdir.c_str()) == -1) {
                if (errno != EEXIST) {
                    std::cerr << "Erro ao criar diretorio: " << subdir << " - " << strerror(errno) << std::endl;
                }
            }
        }
    }

    if (_mkdir(path.c_str()) == -1) {
        if (errno != EEXIST) {
            std::cerr << "Erro ao criar diretorio: " << path << " - " << strerror(errno) << std::endl;
        }
    }
}

void InsertionSort::sort(std::vector<int>& arr) {
    for (size_t j = 2; j < arr.size(); j++) {
        int chave = arr[j];
        size_t i = j - 1;

        while (i < arr.size() && arr[i] > chave) {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = chave;
    }
}

double InsertionSort::sortAndMeasureTime(std::vector<int>& arr) {
    auto start = std::chrono::high_resolution_clock::now();
    sort(arr);
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration<double, std::milli>(end - start).count();
}

void InsertionSort::saveToFile(const std::vector<int>& arr, const std::string& filename, const std::int64_t size) {
    std::string directory = filename.substr(0, filename.find_last_of('/'));
    createDirectoryRecursively(directory); 

    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Erro ao abrir o arquivo: " << filename << std::endl;
        return;
    }
    file << size << "\n"; 
    for (int num : arr) {
        file << num << "\n";
    }
}

void InsertionSort::saveTimeToFile(double time, const std::string& filename) {
    std::string directory = filename.substr(0, filename.find_last_of('/'));
    createDirectoryRecursively(directory); 

    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Erro ao abrir o arquivo: " << filename << std::endl;
        return;
    }
    file << "Tempo de execucao: " << time << " ms" << std::endl;
}

std::vector<int> InsertionSort::generateRandomData(int size) {
    std::vector<int> data(size);
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::generate(data.begin(), data.end(), []() {
        return std::rand() % 10000; 
    });

    return data;
}

std::vector<int> InsertionSort::generateSortedData(int size) {
    std::vector<int> data(size);
    for (int i = 0; i < size; ++i) {
        data[i] = i;
    }
    return data;
}

std::vector<int> InsertionSort::generateReverseSortedData(int size) {
    std::vector<int> data(size);
    for (int i = 0; i < size; ++i) {
        data[i] = size - i - 1;
    }
    return data;
}

void InsertionSort::createDirectories() {
    const char* dirs[] = {
        "./InsertionSort/ArquivosEntrada/Crescente",
        "./InsertionSort/ArquivosEntrada/Decrescente",
        "./InsertionSort/ArquivosEntrada/Random",
        "./InsertionSort/ArquivosSaida/Crescente",
        "./InsertionSort/ArquivosSaida/Decrescente",
        "./InsertionSort/ArquivosSaida/Random",
        "./InsertionSort/ArquivoTempo/Crescente",
        "./InsertionSort/ArquivoTempo/Decrescente",
        "./InsertionSort/ArquivoTempo/Random"
    };

    for (const char* dir : dirs) {
        createDirectoryRecursively(dir);
}

