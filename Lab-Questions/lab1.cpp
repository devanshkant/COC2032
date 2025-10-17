#include <iostream>
#include <string>

using namespace std;
//take input of two fractions using String in the format a/b, find their sum, return the reduced fraction of sum
int gcd(int a, int b){
    if(a == 0)
        return b;    
    return gcd( b%a , a);
}
int main() {
    string s1,s2;
    cout << "Enter fraction 1 in a/b format = \n";
    cin >> s1;
    cout << "Enter fraction 2 in c/d format = \n";
    cin >> s2;
    int i = 0, a = 0, b = 0, c = 0, d = 0;
    while(s1[i] != '/'){
        int digit = s1[i] - '0';
        a = a*10 + digit;
        ++i;
    }
    ++i;
    
    while(i < s1.size()){
        int digit = s1[i] - '0';
        b = b*10 + digit;
        ++i;
    }
    i = 0;  
    
    while(s2[i] != '/'){
        int digit = s2[i] - '0';
        c = c*10 + digit;
        ++i;
    }
    ++i;
    while(i < s2.size()){
        int digit = s2[i] - '0';
        d = d*10 + digit;
        ++i;
    }
    //a/b + c/d = (ad + bc)/bd
    // double sum = (a*d + b*c)/b*d
    int g = gcd(a*d + b*c, b*d);
    cout <<"The sum is " << (a*d + b*c) << '/' << b*d << '\n';
    cout << "The reduced fraction is " << (a*d + b*c)/g << '/' << (b*d)/g << '\n';
    return 0;
}