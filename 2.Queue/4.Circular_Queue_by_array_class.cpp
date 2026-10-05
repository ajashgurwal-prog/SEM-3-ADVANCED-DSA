#include <iostream>
using namespace std;
class CircularQueue {
    private:
        int *arr;
        int front, rear, size;
    public:
        CircularQueue(int s) {
            size = s;
            arr = new int[size];
            front = rear = -1;
        }
        bool isEmpty() {
            return front == -1;
        }   
        bool isFull() {
            return (rear + 1) % size == front;
        }
        void enqueue(int value) {
            if (isFull()) {
                cout << "Queue is full" << endl;
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
                cout << "Queue is empty" << endl;
                return;
            }
            cout << "Value dequeued is: " << arr[front] << endl;
            if (front == rear) {
                front = rear = -1;
            } else {
                front = (front + 1) % size;
            }
        }
        void peek() {
            if (isEmpty()) {
                cout << "Queue is empty" << endl;
                return;
            }
            cout << "Front element is: " << arr[front] << endl;
        }
        void display() {
            if (isEmpty()) {
                cout << "Queue is empty" << endl;
                return;
            }
            cout << "Queue elements are: ";
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
};
int main() {
    int n;
    cout << "Enter size of queue: ";
    cin >> n;
    CircularQueue q(n);
    
    int choice, value;
    do {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                q.display();
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}