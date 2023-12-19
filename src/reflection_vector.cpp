#ifdef USE_BLAS

extern "C"
{
    double dnrm2_(const int *, const double *, const int *);
}


void
gen_ref(int& i, int size_of_matrix, double* x, double* matrix, double& norm)
{
    int ione = 1;
    int len = size_of_matrix - i - 1;
    int pas = i * size_of_matrix;
    for(int j = i + 1; j < size_of_matrix; j++) {
        x[j - i - 1] = matrix[pas + j];
    }
    norm = dnrm2_(&len, x, &ione);
    x[0] -= norm;
    norm *= norm;
    norm -= matrix[pas + i + 1] * matrix[pas + i + 1] - x[0] * x[0];
    norm /= 2;
}

#else

#include <math.h>

void
gen_ref(int& i, int size_of_matrix, double* x, double* matrix, double& norm)
{
    norm = 0;
    int pas = i * size_of_matrix;
    for(int j = i + 1; j < size_of_matrix; j++) {
        x[j - i - 1] = matrix[pas + j];
        norm += matrix[pas + j] * matrix[pas + j];
    }
    if (x[0] > 0) {
        x[0] += std::sqrt(norm);
    } else {
        x[0] -= std::sqrt(norm);
    }
    norm -= matrix[pas + i + 1] * matrix[pas + i + 1] - x[0] * x[0];
    norm /= 2;
}

#endif