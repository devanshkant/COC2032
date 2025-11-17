/*
	Question 4.3
	Create a structure called Volume that uses three variables of type Distance (from the
	ENGLSTRC example) to model the volume of a room. Initialize a variable of type Volume
	to specific dimensions, then calculate the volume it represents, and print out the result.
	To calculate the volume, convert each dimension from a Distance variable to a variable
	of type float representing feet and fractions of a foot, and then multiply the resulting
	three numbers
*/

#include<iostream>
struct Distance{
	int feet;
	int inches;
};
//model the volume of a room
struct Volume{
	Distance l;
	Distance b;
	Distance h;
};
int main(){
    
    return 0;
}