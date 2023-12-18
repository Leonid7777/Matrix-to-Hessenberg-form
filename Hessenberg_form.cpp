#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <fstream>
#include <string>
#include "make_vector.h"
#include "mul.h"

// void
// size_of_matrix_create(int& size_of_matrix)
// {
//     std::string path = "/home/l.burtsev/Desktop/Householder/practicum/in.txt";
//     std::ifstream fin;
//     fin.open(path);

//     if (!fin.is_open())
//     {
//         std::cout << "Ошибка открытия файла!" << std::endl;
//         throw;
//     }
//     else {
//         fin >> size_of_matrix ;
//     }
// }


void
matrix_make(double* matrix, int& size_of_matrix)
{
    // std::string path = "/home/l.burtsev/Desktop/Householder/practicum/in.txt";
    // std::ifstream fin;
    // fin.open(path);
    
    // if (!fin.is_open())
    // {
    //     std::cout << "Ошибка открытия файла!" << std::endl;
    //     throw;
    // }
    // else {
    //     fin >> size_of_matrix ;
    //     for(int j = 0; j < size_of_matrix; j++) {
    //         for(int i = 0; i < size_of_matrix; i++) {
    //             fin >> matrix[i * size_of_matrix + j];
    //         }
    //     }
    // }
    for(int j = 0; j < size_of_matrix; j++) {
        for(int i = 0; i < size_of_matrix; i++) {
            matrix[i * size_of_matrix + j] = j * size_of_matrix + i + 1;
        }
    }
}

int
main(void)
{
    int size_of_matrix = 4096;
    // size_of_matrix_create(size_of_matrix);
    double* matrix = new double[size_of_matrix * size_of_matrix];
    matrix_make(matrix, size_of_matrix);
    double norm = 0;
    double* x = new double[size_of_matrix - 1];

    auto start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < size_of_matrix - 2; i++) {
        make_vector_x(i, size_of_matrix, x, matrix, norm);
        l_matrix_multiplicate(matrix, x, size_of_matrix, size_of_matrix - i - 1, norm);
        r_matrix_multiplicate(matrix, x, size_of_matrix, size_of_matrix - i - 1, norm);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << std::endl;
    
    bool all_is_good = true;
    
    for(int i = 2; i < size_of_matrix; i++) {
        for(int j = 0; j < i - 1; j++) {
            if(fabs(matrix[j *  size_of_matrix + i]) >= std::exp(-15)) {
                all_is_good = false;
            }
        }
    }
    
    std::cout << std::endl;
    
    if(all_is_good) {
        std::cout << "Matrix is correct";
    } else {
        std::cout << "Matrix is incorrect";
    }
    std::cout << std::endl;
    
    std::cout << "Время работы программы: " << duration.count() << " миллисекунд" << std::endl;
    
    std::cout << std::endl;
    return 0;
}
