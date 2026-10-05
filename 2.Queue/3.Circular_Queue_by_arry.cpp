#include <iostream>
using namespace std;

class CircularQueue {
private:
    int *arr;
    int size;
    int front;
    int rear;

public:
    CircularQueue(int n) {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    ~CircularQueue() {
        delete[] arr;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % size == front;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "queue is full" << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }
        arr[rear] = value;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "queue is empty" << endl;
            return;
        }
        cout << "value dequeued is : " << arr[front] << endl;
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "queue is empty" << endl;
            return;
        }
        cout << "front element is : " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "queue is empty" << endl;
            return;
        }
        cout << "queue elements are : ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) {
                break;
            }
            i = (i + 1) % size;
        }
        cout << endl;
    }
};   // <-- class ends here

int main() {   // <-- main is outside and after the class
    int n;
    cout << "enter size of queue : ";
    cin >> n;
    CircularQueue q(n);
    int choice, val;
    cout << "1.enqueue\n2.dequeue\n3.peek\n4.display\n5.exit\n";
    do {
        cout << "enter your choice : ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "enter value to enqueue : ";
                cin >> val;
                q.enqueue(val);
                break;
                
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                q.display();
                break;
            case 5:
                cout << "exiting..." << endl;
                break;
            default:
                cout << "invalid choice" << endl;
        }
    } while (choice != 5);
    return 0;
}