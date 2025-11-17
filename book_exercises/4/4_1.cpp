/*
    Question 4.1
    A phone number, such as (212) 767-8900, can be thought of as having three parts: the
    area code (212), the exchange (767), and the number (8900). Write a program that uses a
    structure to store these three parts of a phone number separately. Call the structure
    phone. Create two structure variables of type phone. Initialize one, and have the user
    input a number for the other one. Then display both numbers. The interchange might
    look like this:
    Enter your area code, exchange, and number: 415 555 1212
    My number is (212) 767-8900
    Your number is (415) 555-1212
*/



#include<iostream>
using namespace std;
//phone number -- area code + the exchange + the number
//by default every member and data is public in structures
struct PhoneNumber{
	//(212) 676-1233
	int AreaCode;
	int Exchange;
	int Number;
	void showPhone(){
		cout << '(' << AreaCode << ')' << ' ' << Exchange << '-' <<Number <<'\n';
	}
};

int main(){
    PhoneNumber MyNumber;
    PhoneNumber YourNumber;
    MyNumber.AreaCode = 212;
    MyNumber.Exchange = 767;
    MyNumber.Number = 8900;
    cout << "My number is ";
    MyNumber.showPhone();
    int ac,ex,nm;
    
    // std::cout << "Enter your area code, exchange and number separated by spaces\n";
    cin >> ac >> ex >> nm;
    
    YourNumber.AreaCode = ac;
    YourNumber.Exchange = ex;
    YourNumber.Number = nm;
    cout << "Your number is ";
    YourNumber.showPhone();

    return 0;
}