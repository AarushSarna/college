#include <iostream>
#include <stdexcept>
using namespace std;

// Abstract base class
class LIST {
public:
    virtual void store(int val) = 0;   // Pure virtual function to insert an element
    virtual int retrieve() = 0;        // Pure virtual function to remove & return an element
    virtual ~LIST() {}                 // Virtual destructor for safe cleanup
};

// Derived Class: Stack (Last-In, First-Out)
class Stack : public LIST {
private:
    int* arr;
    int capacity;
    int topIndex;

public:
    Stack(int cap = 10) : capacity(cap), topIndex(-1) {
        arr = new int[capacity];
    }

    ~Stack() {
        delete[] arr;
    }

    // Overriding store to push onto the stack
    void store(int val) override {
        if (topIndex >= capacity - 1) {
            throw overflow_error("Stack Overflow!");
        }
        arr[++topIndex] = val;
    }

    // Overriding retrieve to pop from top of stack
    int retrieve() override {
        if (topIndex < 0) {
            throw underflow_error("Stack Underflow!");
        }
        return arr[topIndex--];
    }
};

// Derived Class: Queue (First-In, First-Out)
class Queue : public LIST {
private:
    int* arr;
    int capacity;
    int headIndex;
    int tailIndex;
    int count;

public:
    Queue(int cap = 10) : capacity(cap), headIndex(0), tailIndex(0), count(0) {
        arr = new int[capacity];
    }

    ~Queue() {
        delete[] arr;
    }

    // Overriding store to enqueue at the back
    void store(int val) override {
        if (count >= capacity) {
            throw overflow_error("Queue Overflow!");
        }
        arr[tailIndex] = val;
        tailIndex = (tailIndex + 1) % capacity;
        count++;
    }

    // Overriding retrieve to dequeue from the front
    int retrieve() override {
        if (count <= 0) {
            throw underflow_error("Queue Underflow!");
        }
        int val = arr[headIndex];
        headIndex = (headIndex + 1) % capacity;
        count--;
        return val;
    }
};

int main() {
    // Polymorphic pointers using base class LIST
    LIST* myStack = new Stack(5);
    LIST* myQueue = new Queue(5);

    cout << "--- Testing Stack (LIFO) ---" << endl;
    myStack->store(10);
    myStack->store(20);
    myStack->store(30);
    
    cout << "Retrieved: " << myStack->retrieve() << endl; // Output: 30
    cout << "Retrieved: " << myStack->retrieve() << endl; // Output: 20

    cout << "\n--- Testing Queue (FIFO) ---" << endl;
    myQueue->store(100);
    myQueue->store(200);
    myQueue->store(300);

    cout << "Retrieved: " << myQueue->retrieve() << endl; // Output: 100
    cout << "Retrieved: " << myQueue->retrieve() << endl; // Output: 200

    delete myStack;
    delete myQueue;

    return 0;
}