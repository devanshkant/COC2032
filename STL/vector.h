#ifndef     VECTOR_H
#define     VECTOR_H
#include<stdexcept>
class vector{
    private:
        int *data;
        size_t size;
        size_t capacity;
        
        void reallocate(size_t new_capacity){
            /**
             * 1. create new data dynamic array with the new_cap
             * 2. allocate all the existing data again to the new array from the old array
             * 3. free the memory from old memory block
             * 4. make the data pointer point to the new array
             * in this design we make sure memory doesn't get allocated multiple times
             * 
             */
            int *new_data = new int[new_capacity];
            for(size_t i = 0; i < size; ++i){
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
            capacity = new_capacity;
        }
    public:
        vector():data(nullptr), size(0), capacity(0){}
        //destructor

        ~vector(){
            delete[] data;
        }
        //copy constructor
        vector(const vector& other)
            : size(other.size), capacity(other.capacity) {
            data = new int[capacity];
            for(size_t i = 0; i < size; ++i)
                data[i] = other.data[i];
        }

        //copy with assignment operator
        vector& operator=(const vector& other){
            if(this == &other) return *this;

            delete[] data;
            size = other.size;
            capacity = other.capacity;
            data = new int[capacity];
            for(size_t i = 0; i < size; ++i)
                data[i] = other.data[i];

            return *this;
        }

        void push_back(int value){
            if(size == capacity){
                size_t new_capacity = (capacity == 0)? 1 : 2*capacity;
                reallocate(new_capacity);
            }
            data[size++] = value;
        }
        void pop_back(){
            if(size == 0){
                throw std::out_of_range("Vector is Empty!");
            }
            size--;
        }
        int& operator[](size_t index){
            if(index >= size){
                throw std::out_of_range("Index out of range");
            }
            return data[index];
        }
        size_t getSize() const {return size;}
        size_t getCapacity() const {return capacity;}
        
        void reserve(size_t new_capacity){
            if(new_capacity == 0)
                return;
            if(new_capacity > capacity)
                reallocate(new_capacity);
        }
};

#endif