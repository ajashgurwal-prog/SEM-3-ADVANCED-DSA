#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = NULL;
    }
};

class CircularQueue {
private:
    Node* front;
    Node* rear;

public:
    CircularQueue() {
        front = NULL;
        rear = NULL;
    }

    bool isEmpty() {
        return front == NULL;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
            rear->next = front;   // point back to front to make it circular
        } else {
            rear->next = newNode;
            rear = newNode;
            rear->next = front;   // maintain the circular link
        }
        cout << "value enqueued is : " << value << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "queue is empty" << endl;
            return;
        }
        if (front == rear) {
            // only one node in the queue
            delete front;
            front = NULL;
            rear = NULL;
        } else {
            Node* temp = front;
            front = front->next;
            rear->next = front;   // maintain circular link
            cout << "value dequeued is : " << temp->data << endl;
            delete temp;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "queue is empty" << endl;
            return;
        }
        cout << "front element is : " << front->data << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "queue is empty" << endl;
            return;
        }
        cout << "queue elements are : ";
        Node* current = front;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != front);
        cout << endl;
    }
};   // <-- class ends here

int main() {   // <-- main is outside and after the class
    CircularQueue q;
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
                cout << "exiting..." << endl;
                break;
            default:
                cout << "invalid choice" << endl;
        }
    } while (choice != 5);
    return 0;
}