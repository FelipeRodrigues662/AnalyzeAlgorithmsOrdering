#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include <vector>
#include <string>

class Algoritmos {
public:
    virtual void sort(std::vector<int>& arr) = 0; // Método virtual puro
    double sortAndMeasureTime(std::vector<int>& arr);
    void saveToFile(const std::vector<int>& arr, const std::string& filename, const std::int64_t size);
    void saveTimeToFile(double time, const std::string& filename);
    void createDirectories(const std::string& algorithmName);

    std::vector<int> generateRandomData(int size);
    std::vector<int> generateSortedData(int size);
    std::vector<int> generateReverseSortedData(int size);

protected:
    void createDirectoryRecursively(const std::string& path);
};

class InsertionSort : public Algoritmos {
public:
    void sort(std::vector<int>& arr) override;
};

class BubbleSort : public Algoritmos {
public:
    void sort(std::vector<int>& arr) override;
};

class SelectionSort : public Algoritmos {
public:
    void sort(std::vector<int>& arr) override;
};

class ShellSort : public Algoritmos {
public:
    void sort(std::vector<int>& arr) override;
};

class MergeSort : public Algoritmos {
public:
    void sort(std::vector<int>& arr) override;
private:
    void mergeSort(std::vector<int>& arr, int left, int right);
    void merge(std::vector<int>& arr, int left, int mid, int right);
};
#endif // ALGORITMOS_H
