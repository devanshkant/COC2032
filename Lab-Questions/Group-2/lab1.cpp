#include<iostream>
//print Pascal's Triangle
using namespace std;

void CreatePascalTriangle(int **pascal, int n){
    for(int i = 0; i < n; ++i){
        for(int j = 0 ; j <= i; ++j){
            if(j ==0 || j == i )
                pascal[i][j] = 1;
            else
                pascal[i][j] = pascal[i - 1][j] + pascal[i - 1][j - 1];
        }
    }
}
int main(){
    int n;
    cout <<"Enter the power upto which you want the pascal triangle ";
    cin >> n;
    int **pascal = new int*[n + 1];
    for(int i = 0; i <= n; ++i)
        pascal[i] = new int[i + 1];
    CreatePascalTriangle(pascal, n + 1);
    for(int i = 0; i <= n; ++i){
        for(int j = 0; j <= i; ++j){
            cout << pascal[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}