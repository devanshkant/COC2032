#include<iostream>

struct point{
	int x;
	int y;
	point sumCoordinates(point p2){
		point result;
		result.x = x + p2.x;
		result.y = y + p2.y;
		return result;
	}
	void printCoordinate(){
		cout << x << ' ' << y <<'\n';
	}
};


int main(){
    point p1, p2, sum;
    // std::cout << "enter coordinates of p1 ";
    cin >> p1.x >> p1.y;
    // std::cout << "enter coordinates of p2 ";
    cin >> p2.x >> p2.y;

    sum = p1.sumCoordinates(p2);
    cout << "third point is " ;
    sum.printCoordinate();
    return 0;
}