#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <fstream>
#include <string>


void
matrix_make(std::vector<std::vector<double>>& matrix, int& size_of_matrix)
{
    std::string path = "/Users/leonidburtsev/Desktop/in.txt";
    std::ifstream fin;
    fin.open(path);
    
    if (!fin.is_open())
    {
        std::cout << "Ошибка открытия файла!" << std::endl;
        throw;
    }
    else {
        fin >> size_of_matrix ;
        double a;
        for(int i = 0; i < size_of_matrix; i++) {
            std::vector<double> vec;
            for(int j = 0; j < size_of_matrix; j++) {
                fin >> a;
                vec.push_back(a);
            }
            matrix.push_back(vec);
        }
    }
}

void
make_vector_x(int& i, int& size_of_matrix, std::vector<double>& x, std::vector<std::vector<double>>& matrix, double& norm)
{
    double sum = 0;
    for(int j = i + 1; j < size_of_matrix; j++) {
        x.push_back(matrix[j][i]);
        sum += matrix[j][i] * matrix[j][i];
    }
    x[0] -= sqrt(sum);
    norm = (sum - matrix[i + 1][i] * matrix[i + 1][i] + x[0] * x[0]) / 2;
}

void
l_matrix_multiplicate(std::vector<std::vector<double>>& matrix, std::vector<double>& x, int& size_of_matrix, int size_of_vector, double& norm)
{
    int dif = size_of_matrix - size_of_vector;
    
    for(int i = 0; i < size_of_matrix; i++) {
        double sum = 0;
        for(int j = dif; j < size_of_matrix; j++) {
            sum += (matrix[j][i] * x[j - dif]) / norm;
        }
        
        for(int j = dif; j < size_of_matrix; j++) {
            matrix[j][i] -= (x[j - dif] * sum);
        }
    }
}

void
r_matrix_multiplicate(std::vector<std::vector<double>>& matrix, std::vector<double>& x, int& size_of_matrix, int size_of_vector, double& norm)
{
    int dif = size_of_matrix - size_of_vector;
    
    for(int i = 0; i < size_of_matrix; i++) {
        double sum = 0;
        for(int j = dif; j < size_of_matrix; j++) {
            sum += (matrix[i][j] * x[j - dif]) / norm;
        }
        
        for(int j = dif; j < size_of_matrix; j++) {
            matrix[i][j] -= (x[j - dif] * sum);
        }
    }
}

int
main(void)
{
    auto start = std::chrono::high_resolution_clock::now();
    int size_of_matrix;
    std::vector<std::vector<double>> matrix;
    matrix_make(matrix, size_of_matrix);
    for(int i = 0; i < size_of_matrix - 2; i++) {
        std::vector<double> x;
        double norm;
        make_vector_x(i, size_of_matrix, x, matrix, norm);
        l_matrix_multiplicate(matrix, x, size_of_matrix, size_of_matrix - i - 1, norm);
        r_matrix_multiplicate(matrix, x, size_of_matrix, size_of_matrix - i - 1, norm);
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << std::endl;
    
    for(int i = 0; i < size_of_matrix; i++) {
        for(int j = 0; j < size_of_matrix; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    bool all_is_good = true;
    
    for(int i = 2; i < size_of_matrix; i++) {
        for(int j = 0; j < i - 1; j++) {
            if(abs(matrix[i][j]) >= std::exp(-15)) {
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
