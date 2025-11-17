/*	
	Question 4.9
	Create a structure called time. Its three members, all type int, should be called hours,
	minutes, and seconds. Write a program that prompts the user to enter a time value in
	hours, minutes, and seconds. This can be in 12:59:59 format, or each number can be
	entered at a separate prompt (“Enter hours:”, and so forth). The program should then
	store the time in a variable of type struct time, and finally print out the total number of
	seconds represented by this time value:
	long totalsecs = t1.hours*3600 + t1.minutes*60 + t1.seconds
*/


#include<iostream>
using namespace std;
struct Time{
	int hours;
	int minutes;
	int seconds;
	void getInput(){
		char colon;
		cout << "Enter time in hh:mm:ss format (considering the 24 hour clock)\n";
		cin >> hours >> colon >> minutes >> colon >> seconds;
	}
	void printTime() {
        cout << (hours < 10 ? "0" : "") << hours << ':'
             << (minutes < 10 ? "0" : "") << minutes << ':'
             << (seconds < 10 ? "0" : "") << seconds << '\n';
    }
    void printSeconds(){
    	long totalSeconds = hours*3600 + minutes*60 + seconds;
    	cout << totalSeconds <<'\n';
    }
};
int main(){
	Time t;
	t.getInput();
	t.printTime();
	t.printSeconds();
    return 0;
}