#include <math.h>

void
make_vector_x(int& i, int size_of_matrix, double* x, double* matrix, double& norm)
{
    norm = 0;
    int pas = i * size_of_matrix;
    for(int j = i + 1; j < size_of_matrix; j++) {
        x[j - i - 1] = matrix[pas + j];
        norm += matrix[pas + j] * matrix[pas + j];
    }
    x[0] -= sqrt(norm);
    norm -= matrix[pas + i + 1] * matrix[pas + i + 1] - x[0] * x[0];
    norm /= 2;
}
