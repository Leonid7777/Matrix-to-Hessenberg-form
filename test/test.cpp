#include <iostream>
#include <math.h>
#include "reflection_vector.h"
#include "apply_reflection.h"

void
my_test(int size_of_matrix, double* matrix, double* test_reflection_vectors, double* test_norm, double* test_matrix)
{
    double error = 0, norm_matrix = 0;
    for(int i = size_of_matrix - 3; i >= 0; i--) {
        apply_compile_right(matrix, test_reflection_vectors + i * (size_of_matrix - 1), size_of_matrix, size_of_matrix - i - 1, test_norm[i]);
        apply_compile_left(matrix, test_reflection_vectors + i * (size_of_matrix - 1), size_of_matrix, size_of_matrix - i - 1, test_norm[i]);
    }

    for(int i = 0; i < size_of_matrix; i++) {
        for(int j = 0; j < size_of_matrix; j++) {
            norm_matrix += test_matrix[i * size_of_matrix + j] * test_matrix[i * size_of_matrix + j];
            error += (test_matrix[i * size_of_matrix + j] - matrix[i * size_of_matrix + j]) * (test_matrix[i * size_of_matrix + j] - matrix[i * size_of_matrix + j]);
        }
    }


    std::cout << "Error: " << std::sqrt(error) / std::sqrt(norm_matrix) << std::endl;
}