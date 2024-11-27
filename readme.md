# AnalyzeAlgorithmsOrdering

## Descrição do Projeto
O projeto **AnalyzeAlgorithmsOrdering** foi desenvolvido para analisar e comparar o desempenho de diferentes algoritmos de ordenação. Ele permite realizar a ordenação de dados em ordem crescente, decrescente e aleatória para diversas instâncias de tamanhos específicos, salvando os resultados e tempos de execução em arquivos separados.

Os algoritmos de ordenação implementados são:
- Insertion Sort
- Selection Sort
- Bubble Sort
- Shell Sort

## Estrutura de Arquivos e Diretórios
O projeto organiza os resultados e os tempos de execução em uma estrutura de diretórios conforme o algoritmo e o tipo de dados escolhido, com subdiretórios para cada tipo de ordenação e tamanhos de instância.

Exemplo de estrutura de diretórios:
/InsertionSort /ArquivosEntrada /Crescente /Decrescente /Random 
/ArquivosSaida /Crescente /Decrescente /Random 
/ArquivoTempo /Crescente /Decrescente /Random


Cada arquivo segue a convenção de nomes:
- **Entrada**: `input_<tamanho>.txt`
- **Saída**: `output_sorted_<tamanho>.txt`
- **Tempo**: `output_time_<tamanho>.txt`

## Pré-requisitos
- **Compilador C++**: O projeto foi desenvolvido em C++, então é necessário um compilador compatível.
- **Sistema operacional**: Windows (a função `_mkdir` utilizada para criação de diretórios é específica para Windows).

## Compilação e Execução

### Compilação
Para compilar o projeto, execute o seguinte comando no terminal, estando no diretório do projeto:

    g++ -o AnalyzeAlgorithmsOrdering main.cpp Algoritmos.cpp BubbleSort.cpp InsertionSort.cpp SelectionSort.cpp ShellSort.cpp MergeSort.cpp


### Execução
    ./AnalyzeAlgorithmsOrdering

## Teste
### Compilação
Para compilar o projeto, execute o seguinte comando no terminal, estando no diretório do projeto:

    g++ -o Teste_AnalyzeAlgorithmsOrdering TestePA.cpp Algoritmos.cpp BubbleSort.cpp InsertionSort.cpp SelectionSort.cpp ShellSort.cpp MergeSort.cpp


### Execução
    ./Teste_AnalyzeAlgorithmsOrdering