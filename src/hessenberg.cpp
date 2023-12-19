#include "reflection_vector.h"
#include "apply_reflection.h"

void 
hessenberg_function(int size_of_matrix, double* matrix, double* test_reflection_vectors, double* test_norm) 
{   
    double norm = 0;
    double* x = new double[size_of_matrix - 1];
    for(int i = 0; i < size_of_matrix - 2; i++) {
        gen_ref(i, size_of_matrix, x, matrix, norm);
        apply_compile_left(matrix, x, size_of_matrix, size_of_matrix - i - 1, norm);
        apply_compile_right(matrix, x, size_of_matrix, size_of_matrix - i - 1, norm);
        for(int j = 0; j < size_of_matrix - i - 1; j++) {
            test_reflection_vectors[i * (size_of_matrix - 1) + j] = x[j];
        }
        test_norm[i] = norm;
    }
}