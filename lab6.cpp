#include <iostream>
#include <fstream>

// function to read the matrix from file
int read_matrix(int matrix[][10], std::ifstream& file, int size) {
    // the nested for loops to read each matrix. Only have one set of nested loops as its called for each matrix.
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            file >> matrix[i][j];
        }
    }
    return size;
}

// function to display matrix
void print_matrix(const int matrix[][10], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

// function to add the two matrices
void add_matrices(const int matrix1[][10], const int matrix2[][10], int result[][10], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// function for matrix multiplication
void multiply_matrices(const int matrix1[][10], const int matrix2[][10], int result[][10], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < size; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// function to subtract one matrix from other
void subtract_matrices(const int matrix1[][10], const int matrix2[][10], int result[][10], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

// function to update an element of a matrix
void update_element(int matrix[][10], int size) {
    int row, col, newValue;

    // input the row index
    std::cout << "Enter the row index (0 to " << size - 1 << "): ";
    std::cin >> row;
    while (row < 0 || row >= size) {
        std::cout << "Invalid row index! Please enter again: ";
        std::cin >> row;
    }

    // input the column index
    std::cout << "Enter the column index (0 to " << size - 1 << "): ";
    std::cin >> col;
    while (col < 0 || col >= size) {
        std::cout << "Invalid column index! Please enter again: ";
        std::cin >> col;
    }

    // input a new value
    std::cout << "Enter the new value: ";
    std::cin >> newValue;

    matrix[row][col] = newValue;
}

// Function to find the maximum value in a matrix
int get_max_value(const int matrix[][10], int size) {
    int maxValue = matrix[0][0];
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (matrix[i][j] > maxValue) {
                maxValue = matrix[i][j];
            }
        }
    }
    return maxValue;
}

// Function to transpose a matrix
void transpose_matrix(const int matrix[][10], int transposed[][10], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            transposed[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int matrix1[10][10], matrix2[10][10], result[10][10];
    int size;
    
    std::ifstream file("test.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    file >> size; // read the size of the matrix
    size = read_matrix(matrix1, file, size); // read each matrix
    size = read_matrix(matrix2, file, size);
    file.close();

    std::cout << "Matrix 1:" << std::endl; // printing the matrix 1
    print_matrix(matrix1, size); 

    std::cout << "Matrix 2:" << std::endl; // printing the matrix 2
    print_matrix(matrix2, size);

    std::cout << "Adding matrices:" << std::endl; // add the two together into result and then print that matrix
    add_matrices(matrix1, matrix2, result, size);
    print_matrix(result, size);

    std::cout << "Multiplying matrices:" << std::endl; // multiply the two together into result and then print that matrix
    multiply_matrices(matrix1, matrix2, result, size);
    print_matrix(result, size);

    std::cout << "Subtracting matrices:" << std::endl; // subtract the two matrices into result then print that matrix.
    subtract_matrices(matrix1, matrix2, result, size);
    print_matrix(result, size);

    std::cout << "Updating an element of Matrix 1:" << std::endl; // run the update function, which does the work of getting the values and updating matrix1.
    update_element(matrix1, size);
    std::cout << "Matrix 1 after update:" << std::endl; // prints matrix1 after it was changed.
    print_matrix(matrix1, size);

    std::cout << "Max value in Matrix 1: " << get_max_value(matrix1, size) << std::endl; // max value.

    std::cout << "Transpose of Matrix 1:" << std::endl;
    int transposed[10][10];
    transpose_matrix(matrix1, transposed, size);
    print_matrix(transposed, size);

    return 0;
}
