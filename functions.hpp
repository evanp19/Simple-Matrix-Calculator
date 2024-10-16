#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

// Rounding
double roundTwoDecimals(double value) {
    return std::round(value * 100.0) / 100.0;
}

// Inputs
void inputMatrix(std::vector<std::vector<double>>& matrix, int rows, int cols, const std::string& name) {
    std::cout << "Enter the elements of " << name << " (size " << rows << "x" << cols << "):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cin >> matrix[i][j];
        }
    }
}

// Print Matrix
void displayMatrix(const std::vector<std::vector<double>>& matrix) {
    for (const auto& row : matrix) {
        for (double elem : row) {
            std::cout << std::setw(8) << std::fixed << std::setprecision(2) << roundTwoDecimals(elem) << " ";
        }
        std::cout << std::endl;
    }
}

// Adding
std::vector<std::vector<double>> addMatrices(const std::vector<std::vector<double>>& A, const std::vector<std::vector<double>>& B, int rows, int cols) {
    std::vector<std::vector<double>> result(rows, std::vector<double>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    return result;
}

// Subtracting
std::vector<std::vector<double>> subtractMatrices(const std::vector<std::vector<double>>& A, const std::vector<std::vector<double>>& B, int rows, int cols) {
    std::vector<std::vector<double>> result(rows, std::vector<double>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
    return result;
}

// Multplying
std::vector<std::vector<double>> multiplyMatrices(const std::vector<std::vector<double>>& A, const std::vector<std::vector<double>>& B, int rowsA, int colsA, int colsB) {
    std::vector<std::vector<double>> result(rowsA, std::vector<double>(colsB, 0));
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            for (int k = 0; k < colsA; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

// Transpose
std::vector<std::vector<double>> transposeMatrix(const std::vector<std::vector<double>>& matrix, int rows, int cols) {
    std::vector<std::vector<double>> result(cols, std::vector<double>(rows));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
    return result;
}