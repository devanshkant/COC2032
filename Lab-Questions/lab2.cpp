#include <iostream>
using namespace std;
//take input into matrix using pointers and perform matrix multiplication using pointers

int** matrix_multiplication(int **a, int **b) {
    int **res = new int*[3];
    for (int i = 0; i < 3; ++i) {
        res[i] = new int[3];
        for (int j = 0; j < 3; ++j) {
            *(*(res + i) + j) = 0;  // Initialize to 0 using pointers
        }
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                *(*(res + i) + j) += (*(*(a + i) + k)) * (*(*(b + k) + j));
            }
        }
    }
    return res;
}
int main() {
    int **a = new int*[3], **b = new int*[3];
    for(int i = 0; i < 3; ++i){
        a[i] = new int[3];
        b[i] = new int[3];
    }
    //assuming square matrix of order = 3
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            cout << "Enter element \n";
            cin >> *((*a + i)+j);
        }
    }
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            cout << "Enter element \n";
            cin >> *((*b + i)+j);
        }
    }
    int **arr = matrix_multiplication(a,b);
    cout << "\nResult matrix:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << *(*(arr + i) + j) << " ";
        }
        cout << endl;
    }
    
    //De-allocate memory
    for (int i = 0; i < 3; ++i) {
        delete[] a[i];
        delete[] b[i];
        delete[] arr[i];
    }
    delete[] a;
    delete[] b;
    delete[] arr;
    return 0;
}