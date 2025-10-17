#include <iostream>
#include <stdexcept>
using namespace std;
//implement stack Data Structure
class Stack{
    int *arr;
    int capacity;
    int length = -1;
public:
    Stack(int cap){
        if(cap <= 0){
            throw invalid_argument("capacity must be positive");
        }
        this->capacity = cap;
        arr = new int[cap];
    }
    ~Stack(){
        delete[] arr;
    }
    void push(int d){
        if(length  > capacity){
            throw runtime_error("Stack Overflow!");
        }
        length++;
        arr[length] = d;
    }
    int pop(){
        if(length < 0){
            throw runtime_error("Stack Underflow!");
        }
        int item = arr[length];
        length--;
        return item;
    }
    int top(){
        if(length < 0){
            throw runtime_error("Stack Underflow!");
        }
        return arr[length];
    }
    int size(){
        return length + 1;
    }
};
int main() {
    try {
        Stack s(2);
        s.push(1);
        s.push(2);
        // s.push(3); //will throw overflow
        cout << "Top: " << s.top() << endl;  // 2
        cout << "Pop: " << s.pop() << endl;  // 2
        cout << "Size: " << s.size() << endl;  // 1
        // s.pop(); s.pop();  // Second pop throws Underflow
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}