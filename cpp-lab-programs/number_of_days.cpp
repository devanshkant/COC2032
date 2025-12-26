#include <iostream>
using namespace std;

// Function to check leap year
bool isLeap(int year) {
    if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0)
    {
        return true;
    }
    return false;
}


long long totalDays(int d, int m, int y) {
  
    int monthDays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    long long days = 0;

    // days for complete years
    for (int i = 1; i < y; i++) {
        if (isLeap(i))
            days += 366;
        else
            days += 365;
    }

    // days for complete months of current year
    for (int i = 0; i < m - 1; i++) {
        days += monthDays[i];
        if (i == 1 && isLeap(y)) // February in leap year
            days += 1;
    }

    // days of current month
    days += d;

    return days;
}

int main() {
    int d1, m1, y1;
    int d2, m2, y2;

    cout << "Enter first date (dd mm yyyy): ";
    cin >> d1 >> m1 >> y1;

    cout << "Enter second date (dd mm yyyy): ";
    cin >> d2 >> m2 >> y2;

    long long days1 = totalDays(d1, m1, y1);
    long long days2 = totalDays(d2, m2, y2);

    long long result = days2 - days1;
    if (result < 0)
        result = -result;

    // as both days inclusive
    result = result + 1;

    cout << "Total number of days : " << result<< endl;

    return 0;
}
