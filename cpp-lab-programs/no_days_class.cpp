#include <iostream>
using namespace std;
// Number of days in each month :- 30
// No leap year concept
// multiple date format

int convert(char arr[])
{   int num=0;
    char mon[12][3] = { {'j', 'a', 'n'},
                        {'f', 'e', 'b'},
                        {'m', 'a', 'r'},
                        {'a', 'p', 'r'},
                        {'m', 'a', 'y'},
                        {'j', 'u', 'n'},
                        {'j', 'u', 'l'},
                        {'a', 'u', 'g'},
                        {'s', 'e', 'p'},
                        {'o', 'c', 't'},
                        {'n', 'o', 'v'},
                        {'d', 'e', 'c'}
    };
    for(int i=0;i<12;i++){
        for(int j=0;j<3;j++){
            if(mon[i][j]!=arr[j]){
                break;
            }
            if(j==2){
                num=i+1;
                return num;
            }
        }
    }
    return -1;
}
class days
{   public:
    int d;
    int m;
    int y;
    days(int d, int m, int y)
    {
        this->d = d;
        this->m = m;
        this->y = y;
    }
    days(int d, char month[], int y)
    {
        this->d = d;
        this->y = y;
        m=convert(month);
    }
    days(char month[],int d, int y){
        this->d = d;
        this->y = y;
         m=convert(month);
    }
};
 int number_of_days(days d1, days d2)
    {
        int ans = 0;
        int total1 = 0;
        int total2 = 0;
        total1 = (360 * (d1.y - 1)) + (30 * (d1.m - 1)) + d1.d;
        total2 = (360 * (d2.y - 1)) + (30 * (d2.m - 1)) + d2.d;
        if (total1 >= total2)
        {
            ans = total1 - total2 + 1;
        }
        else
        {
            ans = total2 - total1 + 1;
        }
        return ans;
    }

int main()
{
    int choice;
    int date;
    int month;
    int year;
    days d1(1,1,1);
    days d2(1,1,1);
    char month_str[4];
    cout << "For 01/01/2025 , enter 1" << endl;
    cout << "For 01/jan/2025 , enter 2" << endl;
    cout << "for jan/01/2025 , enter 3" << endl;
    cout << "ENTER CHOICE: " << endl;
    cin >> choice;
    if (choice == 1)
    {
        cout << "ENTER DATE 1: ";
        cin >> date >> month >> year;
       d1=days(date,month,year);
        cout << "ENTER DATE 2: ";
        cin >> date >> month >> year;
        d2= days(date,month,year);
    }
    else if (choice == 2)
    {
        cout << "ENTER DATE 1: ";
        cin >> date >> month_str >> year;
        d1=days(date,month_str,year);
         cout << "ENTER DATE 2: ";
        cin >> date >> month_str >> year;
        d2=days(date,month_str,year);
    }
    else if (choice == 3)
    {
        cout << "ENTER DATE 1: ";
        cin >> month_str >> date >> year;
        d1=days(month_str,date,year);
         cout << "ENTER DATE 2: ";
        cin >> month_str >> date >> year;
        d2=days(month_str,date,year);
    }
    else
    {
        cout << "invalid choice" << endl;
        return 0;
    }
    cout<<"NUMBER OF DAYS BETWEEN TWO GIVEN DATES : ";
    cout<<number_of_days(d1,d2)<<endl;
    return 0;

    
}