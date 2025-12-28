#ifndef HEAP_H
#define HEAP_H

class Heap {
protected:
    int* data;
    int size;
    int capacity;

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    // pure virtual comparator
    virtual bool compare(int a, int b) = 0;

    void heapifyUp(int index) {
        while (index > 0 && compare(data[index], data[parent(index)])) {
            swap(data[index], data[parent(index)]);
            index = parent(index);
        }
    }

    void heapifyDown(int index) {
        int best = index;
        int left = leftChild(index);
        int right = rightChild(index);

        if (left < size && compare(data[left], data[best]))
            best = left;

        if (right < size && compare(data[right], data[best]))
            best = right;

        if (best != index) {
            swap(data[index], data[best]);
            heapifyDown(best);
        }
    }

public:
    Heap(int cap) {
        capacity = cap;
        size = 0;
        data = new int[capacity];
    }

    virtual ~Heap() {
        delete[] data;
    }

    void insert(int value) {
        if (size == capacity) return;
        data[size] = value;
        heapifyUp(size);
        size++;
    }

    void delRoot() {
        if (size == 0) return;
        data[0] = data[size - 1];
        size--;
        heapifyDown(0);
    }

    int peek() {
        return (size > 0) ? data[0] : -1;
    }

    bool isEmpty() {
        return size == 0;
    }

    int getSize() {
        return size;
    }

    void buildHeap() {
        for (int i = size / 2 - 1; i >= 0; i--) {
            heapifyDown(i);
        }
    }
};
class MaxHeap : public Heap {
protected:
    bool compare(int a, int b) override {
        return a > b;
    }

public:
    MaxHeap(int cap) : Heap(cap) {}

    int extractMax() {
        int maxVal = peek();
        delRoot();
        return maxVal;
    }

    void deleteValue(int value) {
        for (int i = 0; i < size; i++) {
            if (data[i] == value) {
                data[i] = data[size - 1];
                size--;
                heapifyDown(i);
                heapifyUp(i);
                break;
            }
        }
    }
};
class MinHeap : public Heap {
protected:
    bool compare(int a, int b) override {
        return a < b;
    }

public:
    MinHeap(int cap) : Heap(cap) {}

    int extractMin() {
        int minVal = peek();
        delRoot();
        return minVal;
    }

    void deleteValue(int value) {
        for (int i = 0; i < size; i++) {
            if (data[i] == value) {
                data[i] = data[size - 1];
                size--;
                heapifyDown(i);
                heapifyUp(i);
                break;
            }
        }
    }
};

#endif