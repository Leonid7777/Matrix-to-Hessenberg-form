## PRACTICE BTM
The code for reducing the matrix to a Hessenberg form.
The casting function: hessenberg_function(size_of_matrix, matrix, test_reflection_vectors, test_norm);
size_of_matrix - (int) matrix size
matrix - double* (size_of_matrix * size_of_matrix) the main matrix is written in columns, represented as a vector
test_reflection_vectors - double* (size_of_matrix - 1) * (size_of_matrix - 2) the matrix is written in columns, represented as a vector which store reflection vectors in columns of size (size_of_matrix - 1)
test_norm - double* (size_of_matrix - 2) vector, which store norm^2/2 of reflection vectors

Usage example:

