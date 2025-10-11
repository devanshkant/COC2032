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