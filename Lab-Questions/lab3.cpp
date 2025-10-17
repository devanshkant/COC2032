#include <iostream>
#include <iomanip>
using namespace std;
//homework question
//find inverse of an NxN matrix
void Minor(double **matrix, double **minor, int n, int row, int col) {
    int current_row = 0, current_col = 0;
    for (int i = 0; i < n; ++i) {
        if (i == row) continue;
        current_col = 0; 
        for (int j = 0; j < n; ++j) {
            if (j == col) continue;
            minor[current_row][current_col] = matrix[i][j];
            current_col++;
        }
        current_row++;
    }
}

double determinant(double **matrix, int n) {
    if (n == 1) return matrix[0][0];
    if (n == 2) return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);

    double det = 0;

    double **minor = new double*[n - 1];
    for (int i = 0; i < n - 1; i++) {
        minor[i] = new double[n - 1];
    }

    for (int j = 0; j < n; ++j) {
        Minor(matrix, minor, n, 0, j);
        int sign = (j % 2 == 0) ? 1 : -1;
        det += sign * matrix[0][j] * determinant(minor, n - 1); // Fixed syntax
    }

    for (int i = 0; i < n - 1; i++) {
        delete[] minor[i];
    }
    delete[] minor;
    return det;
}

void adjoint(double **matrix, double **adjoint_matrix, int n) {
    double **minor = new double*[n - 1];
    for (int i = 0; i < n - 1; ++i) {
        minor[i] = new double[n - 1];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            Minor(matrix, minor, n, i, j);
            int sign = ((i + j) % 2 == 0) ? 1 : -1; 
            adjoint_matrix[j][i] = sign * determinant(minor, n - 1); 
        }
    }

    for (int i = 0; i < n - 1; i++) {
        delete[] minor[i];
    }
    delete[] minor;
}

void getInverse(double **matrix, double **inverse, int n, double det) {  

    if (det == 0) {
        cout << "inverse does not exist for this matrix\n";
        return;
    }
    double **adjoint_matrix = new double*[n];
    for (int i = 0; i < n; i++) {
        adjoint_matrix[i] = new double[n];
    }

    adjoint(matrix, adjoint_matrix, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inverse[i][j] = adjoint_matrix[i][j] / det;
        }
    }

    for (int i = 0; i < n; i++) {
        delete[] adjoint_matrix[i];
    }
    delete[] adjoint_matrix;
}
void printMatrix(double **mat, int n){
    cout << "The given matrix is\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << mat[i][j] <<" ";
        }
        cout << '\n';
    }
}
int main() {
    int n;
    cout << "Enter the size of the square matrix (n): ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid matrix size.\n";
        return 1;
    }

    double **matrix = new double*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new double[n];
    }

    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    printMatrix(matrix, n);
    if (n == 1) {
        double det = matrix[0][0];
        if (det == 0) {
            cout << "inverse does not exist for this matrix\n";
        } else {
            cout << "Inverse of the given matrix is " << 1.0 / det << '\n';
        }
        return 0;
    }
    double det = determinant(matrix, n);
    cout << "Determinant of the matrix is " <<det << '\n';

    double **inverse = new double*[n];
    for (int i = 0; i < n; i++) {
        inverse[i] = new double[n];
    }

    getInverse(matrix, inverse, n, det);

    if (det != 0) {
        cout << "Inverse Matrix:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
            	if (inverse[i][j] == 0.0) {
    				inverse[i][j] = 0.0;
				}
                cout << fixed << setprecision(5) << inverse[i][j] << " ";
            }
            cout << '\n';
        }
    }

    // Deallocate matrices
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
        delete[] inverse[i];
    }
    delete[] matrix;
    delete[] inverse;

    return 0;
}