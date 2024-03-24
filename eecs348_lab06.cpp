//Name: Katharine Swann
//Description: Use C++ to perform various operations on square
//             matrices using functions and arrays

#include <iostream> //input/output stream library
#include <fstream> //file stream library for file I/O
#include <iomanip> //input/output manipulation library

//sample input file name: matrix_input.txt

const int N = 3; //N = size of the matrices = 3

//1. read values from a file into a matrix
void readMatrix(int matrix[N][N], const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                file >> matrix[i][j];
            }
        }
        file.close();
    }
}

//2. print a matrix
void printMatrix(const int matrix[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << std::setw(4) << matrix[i][j];
        }
        std::cout << std::endl;
    }
}

//3. add two matrices and place the result in a third matrix;
//   print the result
void addMatrices(const int matrix1[N][N], const int matrix2[N][N], int result[N][N]) {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            result[i][j] = matrix1[i][j] + matrix2[i][j];
}

//4. multiply two matrices and place the result in a third matrix;
//   print the result
void multiplyMatrices(const int matrix1[N][N], const int matrix2[N][N], int result[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < N; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

//5. subtract the second matrix from the first matrix and place the result
//   in a third matrix; print the result
void subtractMatrices(const int matrix1[N][N], const int matrix2[N][N], int result[N][N]) {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            result[i][j] = matrix1[i][j] - matrix2[i][j];
}

//6. Update an element of the first matrix; print the result
void updateElement(int matrix[N][N], int row, int col, int newValue) {
    if (row >= 0 && row < N && col >= 0 && col < N)
        matrix[row][col] = newValue;
}

//7. Get the max value of the first matrix
int getMaxValue(const int matrix[N][N]) {
    int max_val = matrix[0][0];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (matrix[i][j] > max_val)
                max_val = matrix[i][j];
    return max_val;
}

//8. Transpose the first matrix; print the result
void transposeMatrix(const int matrix[N][N], int result[N][N]) {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            result[j][i] = matrix[i][j]; //flip rows and columns
}


int main() {
    int matrix1[N][N];
    int matrix2[N][N];
    int result[N][N];

    //read matrices from file
    readMatrix(matrix1, "matrix_input.txt");
    readMatrix(matrix2, "matrix2_input.txt");

    std::cout << "Matrix 1" << std::endl;
    printMatrix(matrix1);
    std::cout << std::endl; //spacing out results

    std::cout << "Matrix 2" << std::endl;
    printMatrix(matrix2);
    std::cout << std::endl;

    std::cout << "Matrix 1 + Matrix 2 =" << std::endl;
    addMatrices(matrix1, matrix2, result);
    printMatrix(result);
    std::cout << std::endl;

    std::cout << "Matrix 1 * Matrix 2 =" << std::endl;
    multiplyMatrices(matrix1, matrix2, result);
    printMatrix(result);
    std::cout << std::endl;

    std::cout << "Matrix 1 - Matrix 2 =" << std::endl;
    subtractMatrices(matrix1, matrix2, result);
    printMatrix(result);
    std::cout << std::endl;

    updateElement(matrix1, 1, 1, 42); //new value = 42
    std::cout << "Matrix 1 after updating an element:" << std::endl;
    printMatrix(matrix1);
    std::cout << std::endl;

    std::cout << "Max value in Matrix 1 = " << getMaxValue(matrix1) << std::endl;
    std::cout << std::endl;

   std::cout << "Transpose of Matrix 1 =" << std::endl;
    transposeMatrix(matrix1, result);
    printMatrix(result);

    return 0;
}