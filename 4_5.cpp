#include<iostream>
#include<string>
using namespace std;
struct Date{
	int date;
	int month;
	int year;
	void printDate(){
		cout << date <<'/' << month << '/' << year << '\n';
	}
	void getInput(){
		char slash;
		cout << "Enter date in dd/mm/yyyy format \n" ;
		cin >> date >> slash >> month >> slash >> year;
	}
};

int main(){
	Date d;
	d.getInput();
	cout << "The given date is ";
	d.printDate();
    return 0;
}