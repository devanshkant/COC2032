#include <iostream>
#include <string>
#include <cctype>
#include <stdexcept>
#include <limits.h>  // For LLONG_MAX

using namespace std;

string convert_base(const string& num, int M, int N) {
    string int_part, frac_part;
    //jahan par dot hai us index ko store karenge
    int dot_pos = num.find('.');
    
    if (dot_pos != string::npos) {
        int_part = num.substr(0, dot_pos);
        frac_part = num.substr(dot_pos + 1);
    }
    //agar fraction part nahi hai ->
    else {
        int_part = num;
        frac_part = "";
    }

    // Convert integer part to base 10
    long long int_val = 0;
    //har ek letter ko traverse kiya
    for (char ch : int_part) {
        //agar user ne lower case mein input diya, toupper(ch)
        char c = toupper(ch);
        int digit;
        if (isdigit(c)) 
            digit = c - '0';
        else if (c >= 'A' && c <= 'F') 
            digit = 10 + c - 'A';
        else 
            throw invalid_argument("Invalid character");
        //har base mein  0 to M-1 digits hi use hote hain
        if (digit >= M) 
            throw invalid_argument("Digit exceeds base M");
        if (M != 0 && int_val > (LLONG_MAX - digit) / M) throw overflow_error("Integer overflow");
        int_val = int_val * M + digit;
    }

    // Convert fractional part to fraction
    long long frac_num = 0;
    for (char ch : frac_part) {
        char c = toupper(ch);
        int digit;
        if (isdigit(c)) 
            digit = c - '0';
        else if (c >= 'A' && c <= 'F') 
            digit = 10 + c - 'A';
        else 
            throw invalid_argument("Invalid character");
        if (digit >= M) 
            throw invalid_argument("Digit exceeds base M");
        if (M != 0 && frac_num > (LLONG_MAX - digit) / M) 
            throw overflow_error("Fraction overflow");
        frac_num = frac_num * M + digit;
    }

    long long denom = 1;
    int frac_len = frac_part.length();
    for (int i = 0; i < frac_len; ++i) {
        if (M != 0 && denom > LLONG_MAX / M) throw overflow_error("Denominator overflow");
        denom *= M;
    }

    // Convert integer part to base N
    string result;
    long long tmp = int_val;
    if (tmp == 0) {
        result = "0";
    } else {
        while (tmp > 0) {
            int rem = tmp % N;
            char d = (rem < 10) ? '0' + rem : 'A' + rem - 10;
            result = d + result;
            tmp /= N;
        }
    }

    // Convert fractional part to base N
    string frac_n;
    long long rem = frac_num;
    const int MAX_PREC = 20;
    int prec = 0;
    while (rem != 0 && prec < MAX_PREC) {
        if (N != 0 && rem > LLONG_MAX / N) 
            throw overflow_error("Remainder overflow");
        rem *= N;
        long long digit = rem / denom;
        rem %= denom;
        char d = (digit < 10) ? '0' + digit : 'A' + digit - 10;
        frac_n += d;
        prec++;
    }

    // Build result
    string answer = result;
    if (!frac_n.empty()) {
        answer += "." + frac_n;
    }
    return answer;
}

int main() {
    int M, N;
    string num;
    cout << "Enter base M (2-16): ";
    cin >> M;
    cout << "Enter base N (2-16): ";
    cin >> N;
    cout << "Enter number in base M: ";
    cin >> num;

    if (M < 2 || M > 16 || N < 2 || N > 16) {
        cout << "Bases must be between 2 and 16." << endl;
        return 1;
    }

    try {
        string result = convert_base(num, M, N);
        cout << "Result in base " << N << ": " << result << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}