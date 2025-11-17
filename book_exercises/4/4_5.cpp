/*
	Question 4.5
	Create a structure of type date that contains three members: the month, the day of the
	month, and the year, all of type int. (Or use day-month-year order if you prefer.) Have
	the user enter a date in the format 12/31/2001, store it in a variable of type struct date,
	then retrieve the values from the variable and print them out in the same format.
*/


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