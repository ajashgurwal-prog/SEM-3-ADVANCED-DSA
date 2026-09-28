#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;
    int top;
    int size;
public:
    Stack(int n) {
        size = n;
        arr = new int[size];
        top = -1;
    }
    void push(int x) {
        if (top == size - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        arr[top] = x;
    }
    void pop() {
        if (top == -1) {
            cout << "Stack Underflow" << endl;
            return;
        }
        top--;
    }
    int peek() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }
    bool isEmpty() {
        return top == -1;
    }
};