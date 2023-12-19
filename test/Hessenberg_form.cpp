#include <iostream>
#include <cmath>
#include <chrono>
#include "hessenberg.h"
#include "creating_matrix.h"
#include "test.h"


int
main(void)
{
    int size_of_matrix = 4096;
    double* matrix = new double[size_of_matrix * size_of_matrix];
    double* test_matrix = new double[size_of_matrix * size_of_matrix];
    double* test_reflection_vectors = new double[(size_of_matrix - 1) * (size_of_matrix - 2)];
    double* test_norm = new double[size_of_matrix - 2];
    matrix_make(matrix, size_of_matrix);

    for(int i = 0; i < size_of_matrix; i++) {
        for(int j = 0; j < size_of_matrix; j++) {
            test_matrix[i * size_of_matrix + j] = matrix[i * size_of_matrix + j];
        }
    }

    auto start = std::chrono::high_resolution_clock::now();
    hessenberg_function(size_of_matrix, matrix, test_reflection_vectors, test_norm);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    my_test(size_of_matrix, matrix, test_reflection_vectors, test_norm, test_matrix);

    std::cout << "Время работы программы: " << duration.count() << " миллисекунд" << std::endl;

    return 0;
}
