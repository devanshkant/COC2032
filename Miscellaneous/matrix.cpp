#include <iostream>
#include <stdexcept>

using namespace std;

class Matrix {
private:
    int r, c;
    int **mat;

public:
    // Constructor with memory allocation
    Matrix(int rows, int cols) : r(rows), c(cols) {
        if (rows <= 0 || cols <= 0) {
            throw invalid_argument("Rows and columns must be positive");
        }
        mat = new int*[r];
        for (int i = 0; i < r; ++i) {
            mat[i] = new int[c]();  // Zero-initialized
        }
    }

    // Copy constructor (deep copy)
    Matrix(const Matrix& other) : r(other.r), c(other.c) {
        mat = new int*[r];
        for (int i = 0; i < r; ++i) {
            mat[i] = new int[c];
            for (int j = 0; j < c; ++j) {
                mat[i][j] = other.mat[i][j];
            }
        }
    }

    // Assignment operator overloaded (deep copy)
    Matrix& operator=(const Matrix& other) {
        if (this == &other) return *this;
        // Free existing memory
        for (int i = 0; i < r; ++i) {
            delete[] mat[i];
        }
        delete[] mat;
        // Copy
        r = other.r;
        c = other.c;
        mat = new int*[r];
        for (int i = 0; i < r; ++i) {
            mat[i] = new int[c];
            for (int j = 0; j < c; ++j) {
                mat[i][j] = other.mat[i][j];
            }
        }
        return *this;
    }

    // Destructor: free memory
    ~Matrix() {
        for (int i = 0; i < r; ++i) {
            delete[] mat[i];
        }
        delete[] mat;
    }

    // Set data from another int** array
    void setData(int **temp) {
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                mat[i][j] = temp[i][j];
            }
        }
    }

    // Print matrix
    void print() const {
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cout << mat[i][j] << " ";
            }
            cout << "\n";
        }
    }

    // Read/write access
    int& operator()(int i, int j) {
        if (i < 0 || i >= r || j < 0 || j >= c) {
            throw out_of_range("Matrix indices out of range");
        }
        return mat[i][j];
    }

    // Const read access
    const int& operator()(int i, int j) const {
        if (i < 0 || i >= r || j < 0 || j >= c) {
            throw out_of_range("Matrix indices out of range");
        }
        return mat[i][j];
    }

    // Const version for returning a new transposed matrix
    Matrix transpose() const {
        Matrix res(c, r);  // Note: swapped dimensions
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                res.mat[j][i] = mat[i][j];
            }
        }
        return res;
    }

    // Determinant (recursive, for square matrices only)
    int determinant() const {
        if (r != c) {
            throw runtime_error("Determinant requires a square matrix");
        }
        if (r == 1) return mat[0][0];
        if (r == 2) return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];

        int det = 0;
        for (int j = 0; j < c; ++j) {
            Matrix minor(r - 1, c - 1);
            for (int row = 1; row < r; ++row) {
                int col_idx = 0;
                for (int col = 0; col < c; ++col) {
                    if (col == j) continue;
                    minor(row - 1, col_idx++) = mat[row][col];
                }
            }
            int sign = (j % 2 == 0) ? 1 : -1;
            det += sign * mat[0][j] * minor.determinant();
        }
        return det;
    }

    // Scalar multiplication (returns new matrix, no modification)
    Matrix operator*(int k) const {
        Matrix res(r, c);
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                res.mat[i][j] = mat[i][j] * k;
            }
        }
        return res;
    }

    // Matrix multiplication (returns new matrix)
    Matrix operator*(const Matrix& m) const {
        if (c != m.r) {
            throw runtime_error("Cannot multiply: columns of first != rows of second");
        }
        Matrix result(r, m.c);
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < m.c; ++j) {
                result.mat[i][j] = 0;
                for (int k = 0; k < c; ++k) {
                    result.mat[i][j] += mat[i][k] * m.mat[k][j];
                }
            }
        }
        return result;
    }
};

int main() {
    // Example usage (for testing)
    try {
        Matrix a(2, 2);
        a(0, 0) = 1; a(0, 1) = 2;
        a(1, 0) = 3; a(1, 1) = 4;
        cout << "Matrix A:\n";
        a.print();

        Matrix b = a.transpose();
        cout << "Transpose of A:\n";
        b.print();

        cout << "Determinant of A: " << a.determinant() << "\n";

        Matrix c = a * 2;
        cout << "A * 2:\n";
        c.print();

        Matrix d = a * c;
        cout << "A * (A*2):\n";
        d.print();
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}
