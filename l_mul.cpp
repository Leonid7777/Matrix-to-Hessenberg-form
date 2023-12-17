void
l_matrix_multiplicate(double* matrix, double* x, int size_of_matrix, int size_of_vector, double norm)
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
