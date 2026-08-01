// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
void printMatrix(const int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

void inputMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void transposeMatrix(const int src[10][10], int dest[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            dest[j][i] = src[i][j];
        }
    }
}

void addMatrices(const int A[10][10], const int B[10][10], int result[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

void multiplyMatrices(const int A[10][10], const int B[10][10], int result[10][10], int m, int n, int p) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int choice;

    cout << "--- MATRIX OPERATIONS ---" << endl;
    cout << "1. Transpose Matrix" << endl;
    cout << "2. Add Two Matrices" << endl;
    cout << "3. Multiply Two Matrices" << endl;
    cout << "Select operation (1-3): ";
    cin >> choice;

    if (choice == 1) {
        int r, c;
        int mat[10][10], transposed[10][10];

        cout << "Enter number of rows: ";
        cin >> r;
        cout << "Enter number of columns: ";
        cin >> c;

        inputMatrix(mat, r, c);
        transposeMatrix(mat, transposed, r, c);

        cout << "\nOriginal Matrix:\n";
        printMatrix(mat, r, c);

        cout << "\nTransposed Matrix:\n";
        printMatrix(transposed, c, r);

    } else if (choice == 2) {
        int r, c;
        int A[10][10], B[10][10], sum[10][10];

        cout << "Enter number of rows: ";
        cin >> r;
        cout << "Enter number of columns: ";
        cin >> c;

        cout << "\nEnter elements for Matrix A:\n";
        inputMatrix(A, r, c);

        cout << "\nEnter elements for Matrix B:\n";
        inputMatrix(B, r, c);

        addMatrices(A, B, sum, r, c);

        cout << "\nSum of Matrices:\n";
        printMatrix(sum, r, c);

    } else if (choice == 3) {
        int m, n, p;
        int A[10][10], B[10][10], product[10][10];

        cout << "Enter number of rows for Matrix A (M): ";
        cin >> m;
        cout << "Enter number of columns for Matrix A / rows for Matrix B (N): ";
        cin >> n;
        cout << "Enter number of columns for Matrix B (P): ";
        cin >> p;

        cout << "\nEnter elements for Matrix A (" << m << "x" << n << "):\n";
        inputMatrix(A, m, n);

        cout << "\nEnter elements for Matrix B (" << n << "x" << p << "):\n";
        inputMatrix(B, n, p);

        multiplyMatrices(A, B, product, m, n, p);

        cout << "\nProduct Matrix (A x B):\n";
        printMatrix(product, m, p);

    } else {
        cout << "Invalid choice." << endl;
    }

    return 0;
}
