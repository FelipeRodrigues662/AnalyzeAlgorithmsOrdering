#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include <vector>
#include <string>

class InsertionSort {
public:
    void sort(std::vector<int>& arr);
    double sortAndMeasureTime(std::vector<int>& arr);
    void saveToFile(const std::vector<int>& arr, const std::string& filename, const std::int64_t size);
    void saveTimeToFile(double time, const std::string& filename);
    void createDirectories();

    std::vector<int> generateRandomData(int size);
    std::vector<int> generateSortedData(int size);
    std::vector<int> generateReverseSortedData(int size);

private:
    void createDirectoryRecursively(const std::string& path);
};

#endif // INSERTIONSORT_H
