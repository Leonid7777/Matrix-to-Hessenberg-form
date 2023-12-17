void
r_matrix_multiplicate(double* matrix, double* x, int size_of_matrix, int size_of_vector, double norm)
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