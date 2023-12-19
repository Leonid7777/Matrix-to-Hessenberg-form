#ifdef USE_BLAS

extern "C"
{
    void dgemv_(const char *, const int *, const int *, const double *, const double *, const int *, const double *, const int *, const double *, double *, const int *);
    void dger_(const int *, const int *, const double *, const double *, const int *, const double *, const int *, double *, const int *);
}

void
apply_compile_left(double* matrix, double* x, int size_of_matrix, int size_of_vector, double norm)
{
    int dif = size_of_matrix - size_of_vector;
    int i_one = 1, size_of_vector_1 = size_of_vector + 1;
    double sum, d_one = 1;
    double* vector_sum = new double[size_of_vector + 1];
    char T = 'T';
    double rev_norm = -1 / norm, d_zero = 0;

    dgemv_(&T, &size_of_vector, &size_of_vector_1, &rev_norm, matrix + (dif - 1) * size_of_matrix + dif, &size_of_matrix, x, &i_one, &d_zero, vector_sum, &i_one);
    dger_(&size_of_vector, &size_of_vector_1, &d_one, x, &i_one, vector_sum, &i_one, matrix + (dif - 1) * size_of_matrix + dif, &size_of_matrix);
    delete[] vector_sum;
}

void
apply_compile_right(double* matrix, double* x, int size_of_matrix, int size_of_vector, double norm)
{
    char N = 'N';
    double rev_norm = 1 / norm, d_zero = 0, d_m_one = -1;
    int dif = size_of_matrix - size_of_vector, i_one = 1;
    int size_of_vector_1 = size_of_vector + 1;
    double* vector_sum = new double[size_of_vector + 1];

    dgemv_(&N, &size_of_vector_1, &size_of_vector, &rev_norm, matrix + dif * size_of_matrix + dif - 1, &size_of_matrix, x, &i_one, &d_zero, vector_sum, &i_one);
    dger_(&size_of_vector_1, &size_of_vector, &d_m_one, vector_sum, &i_one, x, &i_one,  matrix + dif * size_of_matrix + dif - 1, &size_of_matrix);
    delete[] vector_sum;
}

#else

void
apply_compile_left(double* matrix, double* x, int size_of_matrix, int size_of_vector, double norm)
{
    int dif = size_of_matrix - size_of_vector;
    double sum;
    for(int i = dif - 1; i < size_of_matrix; i++) {
        sum = 0;
        for(int j = dif; j < size_of_matrix; j++) {
            sum += (matrix[i *  size_of_matrix + j] * x[j - dif]);
        }
        sum /= norm;
        for(int j = dif; j < size_of_matrix; j++) {
            matrix[i *  size_of_matrix + j] -= (x[j - dif] * sum);
        }
    }
}

void
apply_compile_right(double* matrix, double* x, int size_of_matrix, int size_of_vector, double norm)
{
    int dif = size_of_matrix - size_of_vector;
    
    double* vector_sum = new double[size_of_matrix - dif + 1];

    for(int j = dif; j < size_of_matrix; j++) {
        for(int i = dif - 1; i < size_of_matrix; i++) {
            vector_sum[i - dif + 1] += (matrix[j * size_of_matrix + i] * x[j - dif]);
        }
    }

    for(int i = 0; i < size_of_matrix - dif + 1; i++) {
        vector_sum[i] /= norm;
    }

    for(int j = dif; j < size_of_matrix; j++) {
        for(int i = dif - 1; i < size_of_matrix; i++) {
            matrix[j * size_of_matrix + i] -= (x[j - dif] * vector_sum[i - dif + 1]);
        }
    }
}

#endif
