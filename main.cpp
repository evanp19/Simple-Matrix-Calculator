#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include "functions.hpp"


int main() {
    int operation;
    int rowsA, colsA, rowsB, colsB;

    std::cout << "Matrix Calculator\n";
    std::cout << "Select the operation by saying the number:\n";
    std::cout << "1. Add\n";
    std::cout << "2. Subtract\n";
    std::cout << "3. Multiply\n";
    std::cout << "4. Transpose Matrix\n";
    std::cin >> operation;

    if (operation == 1 || operation == 2 || operation == 3) {

        std::cout << "Enter the size of Matrix A (rows cols): ";
        std::cin >> rowsA >> colsA;
        std::cout << "Enter the size of Matrix B (rows cols): ";
        std::cin >> rowsB >> colsB;
    } else if (operation == 4) {
        std::cout << "Enter the size of Matrix (rows cols): ";
        std::cin >> rowsA >> colsA;
    } else {
        std::cout << "Not a valid choice, exiting";
        return 0;
    }


    std::vector<std::vector<double>> matrixA(rowsA, std::vector<double>(colsA));
    std::vector<std::vector<double>> matrixB;

    if (operation == 1 || operation == 2 || operation == 3) {
        matrixB = std::vector<std::vector<double>>(rowsB, std::vector<double>(colsB));
    }


    inputMatrix(matrixA, rowsA, colsA, "Matrix A");

    if (operation == 1 || operation == 2 || operation == 3) {

        inputMatrix(matrixB, rowsB, colsB, "Matrix B");
    }

    std::vector<std::vector<double>> result;
    switch (operation) {
        case 1:
            if (rowsA == rowsB && colsA == colsB) {
                result = addMatrices(matrixA, matrixB, rowsA, colsA);
                std::cout << "Result of Matrix A + Matrix B:\n";
                displayMatrix(result);
            } else {
                std::cout << "Matrices must have the same dimensions for addition\n";
            }
            break;

        case 2:
            if (rowsA == rowsB && colsA == colsB) {
                result = subtractMatrices(matrixA, matrixB, rowsA, colsA);
                std::cout << "Result of Matrix A - Matrix B:\n";
                displayMatrix(result);
            } else {
                std::cout << "Matrices must have the same dimensions for subtraction\n";
            }
            break;

        case 3:
            if (colsA == rowsB) {
                result = multiplyMatrices(matrixA, matrixB, rowsA, colsA, colsB);
                std::cout << "Result of Matrix A * Matrix B:\n";
                displayMatrix(result);
            } else {
                std::cout << "For multiplication, the number of columns in Matrix A must equal the number of rows in Matrix B!\n";
            }
            break;

        case 4:
            result = transposeMatrix(matrixA, rowsA, colsA);
            std::cout << "Transpose of Matrix A:\n";
            displayMatrix(result);
            break;

        default:
            std::cout << "Invalid operation!\n";
    }

    return 0;
}