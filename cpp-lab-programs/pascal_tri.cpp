#include <iostream>
using namespace std;
int fact(int n){
    if(n==1||n==0){
        return 1;
    }
    return n*fact(n-1);
}
int comb(int n,int r){
    int diff=n-r;
    return fact(n)/(fact(r)*fact(diff));
}
void pascal_tri(int n){  
    for(int i=0;i<n;i++){
        for (int s = 1; s <= n - i; s++) {
            cout << " ";
        }
        for(int j=0;j<=i;j++){
            cout<<comb(i,j)<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cout<<"Enter the numbers of rows : ";
    cin>>n;
    pascal_tri(n);
    return 0;
}