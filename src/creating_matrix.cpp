#include <chrono>
#include <cstdlib>

void
matrix_make(double* matrix, int& size_of_matrix)
{
    std::srand(std::time(nullptr));
    for(int j = 0; j < size_of_matrix; j++) {
        for(int i = 0; i < size_of_matrix; i++) {
            matrix[i * size_of_matrix + j] = -1000.0 + 2000.0 * double(std::rand()) / RAND_MAX;
        }
    }
}