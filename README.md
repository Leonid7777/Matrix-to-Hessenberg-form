## PRACTICE BTM
## The code for reducing the matrix to a Hessenberg form.
### The main function: hessenberg_function(size_of_matrix, matrix, test_reflection_vectors, test_norm);
#### Arguments
1. int size_of_matrix - matrix size;
2. double* matrix[size_of_matrix * size_of_matrix] - The main matrix is written in columns, represented as a vector
3. double* test_reflection_vectors[size_of_matrix - 1) * (size_of_matrix - 2)]; The matrix is written in columns, represented as a vector which store reflection vectors in 4. columns of size (size_of_matrix - 1)
4. double* test_norm [size_of_matrix - 2]; Vector, which store norm^2/2 of reflection vectors

#### The Complexity of the Algorithm:
The algorithm has a complexity n^3.
1. Time of work of algorithm without LAPACK: matrix[4096 * 4096] for about 42 seconds.
2. Time of work of algorithm with LAPACK: matrix[4096 * 4096] for about 52 seconds.

#### Usage example 
##### 1. (without LAPACK):
``` shell
mkdir build
cd build/
cmake ../
make
./test/test
```

##### 2. (with LAPACK):
``` shell
mkdir build
cd build/
cmake ../ -DBUILD_BLAS=ON
make
./test/test
```
