#include<iostream>
#include<cmath>
const double M_PI = std::acos(-1.0);
using namespace std;
//27 October 2025
//create abstract base class Shape, derived Classes: Rectangle, Triangle, Pentagon
//attributes: coordinates of vertices in (x,y) format
//store coordinates in C-styled array of the class point
//methods: area(), perimeter() 

//template class Point to store coordinates
template <typename T>
class Point{
        T x;
        T y;
    public:
        Point(T x=0, T y=0):x(x), y(y){}
        T getX(){ return x; }
        T getY(){ return y; }
        //overloading - operator to calculate distance between two points using Distance formula
        double operator-(const Point &p){
            double ans = sqrt((x - p.x)*(x - p.x) + (y - p.y)*(y - p.y));
            return ans;
        }
};
//Abstract Base Class Shape
class Shape{
    protected:
        Point<int> *vertices;
        int num_vertices;
    public:
        //parametrised constructor
        Shape(int n): num_vertices(n){
            vertices = new Point<int>[n];
        }       
        virtual double area() = 0;          //pure virtual function
        virtual double perimeter() = 0;     //pure virtual function
        //destructor
        virtual ~Shape(){
            //line 29 mein dynamically memory allocate kiya hai isliye yahan free karna padega
            delete[] vertices;
        }
};
class Triangle : public Shape{
    public:
        Triangle(): Shape(3){}
        double perimeter() override {
            double ans = 0.0;
            for(int i=0; i<num_vertices; i++){
                ans += vertices[i] - vertices[(i+1)%num_vertices];
            }
            return ans;
        }
        double area() override {
            double ans = 0.0;
            double semi_perimeter = perimeter() / 2.0;
            double a = vertices[0] - vertices[1];
            double b = vertices[1] - vertices[2];   
            double c = vertices[2] - vertices[0];
            //apply Heron's formula
            ans = sqrt(semi_perimeter * (semi_perimeter - a)*(semi_perimeter - b)*(semi_perimeter - c));
            return ans;
        }    
};
class Rectangle : public Shape{
    public:
        Rectangle(): Shape(4){}
        double perimeter() override {
            double ans = 0.0;
            for(int i=0; i<num_vertices; i++){
                ans += vertices[i] - vertices[(i+1)%num_vertices];
            }
            return ans;
        }
        double area() override {
            double length = vertices[0] - vertices[1];
            double breadth = vertices[1] - vertices[2];
            return length * breadth;
        }    
};
//it is to considered a regular pentagon
class Pentagon : public Shape{
    public:
        Pentagon(): Shape(5){}
        double perimeter() override {
            double ans = 0.0;
            for(int i=0; i<num_vertices; i++){
                ans += vertices[i] - vertices[(i+1)%num_vertices];
            }
            return ans;
        }
        double area() override {
            // alternate formula : A = 5/2* R^2 * sin(72)
            // R is the distance from center to a vertex
            //center is the average of all vertices
            Point<int> center;
            for(int i = 0; i < num_vertices; i++){
                center = Point<int>(center.getX() + vertices[i].getX(), center.getY() + vertices[i].getY());
            }
            double R = center - vertices[0];
            double ans = 5/2 * R * R * sin(0.4 * M_PI);
            return ans;
        }
};
/*learnings:
    1.how to make abstract base class using pure virtual functions
    2.how to derive classes from abstract base class and override pure virtual functions
    3.use of C-styled arrays to store self-created classes objects
    4.how to use the value of M_PI constant from cmath library using arccos(-1.0)
*/
int main(){
    
    return 0;
}