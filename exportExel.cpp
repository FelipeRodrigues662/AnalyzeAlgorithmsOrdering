#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

struct SortData {
    std::string inputSize;
    std::string crescente;
    std::string decrescente;
    std::string randomico;
};


std::string readFile(const std::string& filepath) {
    std::ifstream file(filepath);
    if (!file.is_open()) {
        std::cerr << "Erro ao abrir o arquivo: " << filepath << std::endl;
        return "";
    }

    std::string line;
    std::getline(file, line);  
    file.close();


    size_t startPos = line.find(":");  
    size_t endPos = line.find("s");   
    
    if (startPos != std::string::npos && endPos != std::string::npos && endPos > startPos) {
        return line.substr(startPos + 1, endPos - startPos - 1);  
    }

    return "";
}


void processAlgorithm(const std::string& algorithmFolder, const std::vector<std::string>& sizes, std::vector<SortData>& data) {
   
    std::vector<std::string> inputTypes = { "Crescente", "Decrescente", "Random" };

    for (const auto& size : sizes) {
        SortData sortData;
        sortData.inputSize = size;

        for (const auto& inputType : inputTypes) {
            std::string filepath = algorithmFolder + "/ArquivoTempo/" + inputType + "/output_time_" + size + ".txt";
            std::string tempo = readFile(filepath);
            
            if (inputType == "Crescente") {
                sortData.crescente = tempo;
            } else if (inputType == "Decrescente") {
                sortData.decrescente = tempo;
            } else if (inputType == "Random") {
                sortData.randomico = tempo;
            }
        }

        data.push_back(sortData);
    }
}

void exportToCSV(const std::vector<SortData>& insertionData, const std::vector<SortData>& bubbleData,
                   const std::vector<SortData>& selectionData, const std::vector<SortData>& shellData) {
    std::ofstream csvFile("AlgoritmosOrdenacao.csv");
    if (!csvFile.is_open()) {
        std::cerr << "Erro ao criar o arquivo CSV." << std::endl;
        return;
    }

    auto writeAlgorithmData = [&csvFile](const std::string& algorithmName, const std::vector<SortData>& data) {
        csvFile << algorithmName << "\n"; 
        csvFile << "InputSize,Crescente,Decrescente,Randomico\n"; 

        // Dados
        for (const auto& entry : data) {
            csvFile << entry.inputSize << ","
                    << entry.crescente << ","
                    << entry.decrescente << ","
                    << entry.randomico << "\n";
        }

        csvFile << "\n"; 
    };

    writeAlgorithmData("InsertionSort", insertionData);
    writeAlgorithmData("BubbleSort", bubbleData);
    writeAlgorithmData("SelectionSort", selectionData);
    writeAlgorithmData("ShellSort", shellData);

    csvFile.close();
}

int main() {
    std::vector<SortData> insertionData, bubbleData, selectionData, shellData;

    std::vector<std::string> sizes = { "10", "100", "1000", "10000", "100000", "1000000" };

    processAlgorithm("BubbleSort", sizes, bubbleData);
    processAlgorithm("InsertionSort", sizes, insertionData);
    processAlgorithm("SelectionSort", sizes, selectionData);
    processAlgorithm("ShellSort", sizes, shellData);

    exportToCSV(insertionData, bubbleData, selectionData, shellData);

    std::cout << "Processamento concluído e arquivo CSV gerado." << std::endl;
    return 0;
}
