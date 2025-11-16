#include <iostream>
#include <memory>
#include <vector>
using namespace std;

//std::unique_ptr is ideal for scenarios where a single owner manages a resource's lifetime, 
//and ownership might need to be transferred but not shared. 

// Example 1: Basic replacement for new/delete
void basicUsage() {
    // Old way: int* ptr = new int(42); ... delete ptr;
    std::unique_ptr<int> ptr = std::make_unique<int>(42);
    cout << "\nValue: " << *ptr << '\n';
    // Automatic cleanup, no delete needed
}

// Example 2: Dynamic array (1D)
void dynamicArray() {
    int size = 5;
    // Old way: int* arr = new int[size]; ... delete[] arr;
    std::unique_ptr<int[]> arr = std::make_unique<int[]>(size);
    
    for(int i = 0; i < size; i++) {
        arr[i] = i * 10;
        cout << arr[i] << " ";
    }
    cout << '\n';
}

// Example 3: 2D array using array of unique_ptrs
void twoDArray() {
    int rows = 3, cols = 4;
    // Old way: int** arr = new int*[rows]; for(...) arr[i] = new int[cols];
    
    auto arr = std::make_unique<std::unique_ptr<int[]>[]>(rows);
    for(int i = 0; i < rows; i++) {
        arr[i] = std::make_unique<int[]>(cols);
        for(int j = 0; j < cols; j++) {
            arr[i][j] = i * cols + j;
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
}
// In classes, use it for members that represent uniquely owned resources 
//(e.g., a private implementation or pimpl idiom), avoiding the need for manual cleanup in destructors.

// Example 4: Class object management
class MyClass {
public:
    MyClass(int val) : value(val) { 
        cout << "Constructed: " << value << '\n'; 
    }
    ~MyClass() { 
        cout << "Destroyed: " << value << '\n'; 
    }
    int value;
};
//linked list using Smart pointers
template<typename T>
class Node{
    T val;
    std::unique_ptr<Node<T>> next; 
public:
    Node(T value) : val(value), next(nullptr) {} 
};  

void classObject() {
    // Old way: MyClass* obj = new MyClass(100); ... delete obj;
    std::unique_ptr<MyClass> obj = std::make_unique<MyClass>(100);
    cout << "Value: " << obj->value << endl;
}

// Example 5: Transferring ownership
std::unique_ptr<int> createResource() {
    return std::make_unique<int>(999);
}

void ownershipTransfer() {
    std::unique_ptr<int> ptr1 = std::make_unique<int>(50);
    std::unique_ptr<int> ptr2 = std::move(ptr1); // Transfer ownership
    // ptr1 is now nullptr
    cout << "ptr1 is " << (ptr1 ? "valid" : "null") << '\n';
    cout << "ptr2: " << *ptr2 << '\n';
    
    std::unique_ptr<int> ptr3 = createResource();
    cout << "From function: " << *ptr3 << '\n';
}

// Example 6: unique_ptr in containers
void inContainers() {
    std::vector<std::unique_ptr<MyClass>> vec;
    vec.push_back(std::make_unique<MyClass>(1));
    vec.push_back(std::make_unique<MyClass>(2));
    vec.push_back(std::make_unique<MyClass>(3));
    
    for(const auto& ptr : vec) {
        cout << "Element: " << ptr->value << '\n';
    }
    // All objects automatically destroyed when vec goes out of scope
}

// Example 7: Custom deleter
void customDeleter() {
    auto deleter = [](int* p) {
        cout << "Custom delete called" << '\n';
        delete p;
    };
    
    std::unique_ptr<int, decltype(deleter)> ptr(new int(77), deleter);
}

int main() {
    cout << "=== Basic Usage ===" << '\n';
    basicUsage();
    
    cout << "\n=== Dynamic Array ===" << '\n';
    dynamicArray();
    
    cout << "\n=== 2D Array ===" << '\n';
    twoDArray();
    
    cout << "\n=== Class Object ===" << '\n';
    classObject();
    
    cout << "\n=== Ownership Transfer ===" << '\n';
    ownershipTransfer();
    
    cout << "\n=== In Containers ===" << '\n';
    inContainers();
    
    cout << "\n=== Custom Deleter ===" << '\n';
    customDeleter();
    
    return 0;
}