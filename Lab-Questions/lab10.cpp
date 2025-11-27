#include<iostream>
#include<algorithm>
#include<exception>
using namespace std;
//take two array A, B. Both have different sizes
//Store A[i]/B[i] in SafeArray
//throw exception when both are zero
//if array A has more size, throw exception for the extra elements
//18 November 2025
class ZeroDivisionError : public exception {
public:
    const char* what() const noexcept override {
        return "Error: Zero by Zero Division";
    }
};

class DivisionByZeroError : public exception {
public:
    const char* what() const noexcept override {
        return "Error: Division by Zero";
    }
};

class DivisionByNullValueError : public exception {
public:
    const char* what() const noexcept override {
        return "Error: Extra elements in the first Array";
    }
}; 
//template for SafeArray
template<typename T>
class SafeArray{
    private:
        T *arr;
        int size;       //actual no. of elememts in the array
        int capacity;   //capacity with which we declare
    public:
        SafeArray(int n) : capacity(n), size(0){
            arr = new T[n];
        }
        //destrucotr
        ~SafeArray(){
            delete[] arr;
        }
        void SetValue(T data){
            if(size < capacity){
                arr[size] = data;
                size++;
            }
        }
        void Display() const{
            for(int i = 0; i < size; ++i)
                cout << arr[i] << ", ";
            cout << '\n';
        }
};

int main(){
    int n,m;

    cout << "Enter the size of the array a ";
    cin >> n;
    cout << "Enter the size of the array b ";
    cin >> m;
    int *a = new int[n];
    int *b = new int[m];

    cout << "\nEnter elements of the Array a\n";
    for(int i = 0 ; i < n; ++i){
        cout << "Enter element \n";
        cin >> a[i];
    }
    cout << "\nEnter elements of the array b\n";
    for(int i = 0; i < m; ++i){
        cout << "Enter Element \n";
        cin >> b[i];
    }
    int k = min(m,n);   //size of the smaler array

    SafeArray<double> result(k);
    
    //there can be 3 Cases:
        //1. Size(A) == Size(B)
        //2. Size(A) > Size(B)
        //3. Size(A) < Size(B): discard, since we are asked for A[i]/B[i]
    for (int i = 0; i < k; ++i) {
        try {
            if (a[i] == 0 && b[i] == 0)
                throw ZeroDivisionError();

            if (b[i] == 0)
                throw DivisionByZeroError();

            result.SetValue(static_cast<double>(a[i]) / b[i]);
        }catch (exception& e) {
            cout << "Index " << i << " -> Exception: " << e.what() << endl;
        }
    }

    // Check for extra A elements
    try {
        if (n > m)
            throw DivisionByNullValueError();
    }
    catch (exception& e) {
        cout << "\nException: " << e.what() << endl;
    }

    cout << "\nResult array (computed values): ";
    result.Display();
    delete[] a;
    delete[] b;
    return 0;
}