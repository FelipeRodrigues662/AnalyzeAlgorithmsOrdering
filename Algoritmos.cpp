#include "Algoritmos.h"
#include <fstream>
#include <chrono>
#include <direct.h>   
#include <iostream>
#include <algorithm>  
#include <cstdlib>    
#include <ctime>      
#include <sys/stat.h> 
#include <cerrno>     
#include <cstring>    

void Algoritmos::createDirectoryRecursively(const std::string& path) {
    std::string::size_type pos = 0;
    while ((pos = path.find_first_of("\\/", pos)) != std::string::npos) {
        std::string subdir = path.substr(0, pos++);
        if (!subdir.empty()) {
            _mkdir(subdir.c_str()); 
        }
    }
    _mkdir(path.c_str()); 
}


double Algoritmos::sortAndMeasureTime(std::vector<int>& arr) {
    auto start = std::chrono::high_resolution_clock::now();
    sort(arr);
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration<double, std::milli>(end - start).count();
}

void Algoritmos::saveToFile(const std::vector<int>& arr, const std::string& filename, const std::int64_t size) {
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

void Algoritmos::saveTimeToFile(double time, const std::string& filename) {
    std::string directory = filename.substr(0, filename.find_last_of('/'));
    createDirectoryRecursively(directory); 

    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Erro ao abrir o arquivo: " << filename << std::endl;
        return;
    }
    file << "Tempo de execução: " << time << " ms" << std::endl;
}

std::vector<int> Algoritmos::generateRandomData(int size) {
    std::vector<int> data(size);
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::generate(data.begin(), data.end(), []() {
        return std::rand() % 10000; 
    });

    return data;
}

std::vector<int> Algoritmos::generateSortedData(int size) {
    std::vector<int> data(size);
    for (int i = 0; i < size; ++i) {
        data[i] = i;
    }
    return data;
}

std::vector<int> Algoritmos::generateReverseSortedData(int size) {
    std::vector<int> data(size);
    for (int i = 0; i < size; ++i) {
        data[i] = size - i - 1;
    }
    return data;
}

void Algoritmos::createDirectories(const std::string& algorithmName) {
    std::vector<std::string> directories = {
        algorithmName + "/ArquivosEntrada/Crescente",
        algorithmName + "/ArquivosEntrada/Decrescente",
        algorithmName + "/ArquivosEntrada/Random",
        algorithmName + "/ArquivosSaida/Crescente",
        algorithmName + "/ArquivosSaida/Decrescente",
        algorithmName + "/ArquivosSaida/Random",
        algorithmName + "/ArquivoTempo/Crescente",
        algorithmName + "/ArquivoTempo/Decrescente",
        algorithmName + "/ArquivoTempo/Random"
    };

    for (const auto& dir : directories) {
        createDirectoryRecursively(dir);
    }
}

