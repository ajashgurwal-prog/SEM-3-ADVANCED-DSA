#include <iostream>
using namespace std;   
class Node {
    public:
    int data;
    Node* next; 
    Node(int value) {
        data = value;
        next = NULL;
    };
};
    class Stack {
        Node* top;
        public:
        Stack() {
            top = NULL;
        }
    
        bool isEmpty() {
            return top == NULL;
        }
        void push(int value) {
            Node* newNode = new Node(value);
            newNode->next = top;
            top = newNode;
            cout << "value pushed to stack" << value << endl;
        }
        void pop() {
            if (top == NULL) {
                cout << "Stack is empty" << endl;
                return;
            }
            Node* temp = top;
            top = top->next;
            delete temp;
        } 
        void peek(){
            if(isEmpty()) {
                cout << "Stack is empty" << endl;
                return;
            }
            cout << "Top element is: " << top->data << endl;
        }
        void display() {
            if (isEmpty()) {
                cout << "Stack is empty" << endl;
                return;
            }
            Node* current = top;
            cout << "Stack elements: ";
            while (current != NULL) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
        };
        int main() {
            Stack s;
            int choice, val;
            do {
                cout << "1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\nEnter your choice: ";
                cin >> choice;
                switch (choice) {
                    case 1:
                        cout << "Enter value to push: ";
                        cin >> val;
                        s.push(val);
                        break;
                    case 2:
                        s.pop();
                        break;
                    case 3:
                        s.peek();
                        break;
                    case 4:
                        s.display();
                        break;
                    case 5:
                        cout << "Exiting..." << endl;
                        break;
                    default:
                        cout << "Invalid choice" << endl;
                }
            } while (choice != 5);
            return 0;
        }