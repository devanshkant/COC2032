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