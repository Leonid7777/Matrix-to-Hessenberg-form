#include "reflection_vector.h"
#include "multiplication_by_the_reflection_matrix.h"

void 
hessenberg_function(int size_of_matrix, double* matrix, double* test_reflection_vectors, double* test_norm) 
{   
    double norm = 0;
    double* x = new double[size_of_matrix - 1];
    for(int i = 0; i < size_of_matrix - 2; i++) {
        creating_a_reflection_vector(i, size_of_matrix, x, matrix, norm);
        multiplication_by_the_reflection_matrix_on_the_left(matrix, x, size_of_matrix, size_of_matrix - i - 1, norm);
        multiplication_by_the_reflection_matrix_on_the_right(matrix, x, size_of_matrix, size_of_matrix - i - 1, norm);
        for(int j = 0; j < size_of_matrix - i - 1; j++) {
            test_reflection_vectors[i * (size_of_matrix - 1) + j] = x[j];
        }
        test_norm[i] = norm;
    }
}