#include <iostream>
using namespace std;
class Node{
    public :
    int data;
    Node* next;
    Node(int value){
        data = value;
        next = NULL;
    };
};
class queue{
    private :
    Node* front;
    Node* rear;
    public :
    queue(){
        front= NULL;
        rear= NULL;
    }
    bool isEmpty(){
        return front==NULL;
    }
    void enqueue(int value){
        Node* newNode = new Node(value);
        if (isEmpty()){
            front = newNode;
            rear = newNode;
        }
        else{
            rear->next = newNode;
            rear = newNode;
        }
        cout<<"value enqueued is : "<<value <<endl;
    }
    void dequeue(){
        if (isEmpty()){
            cout<<"queue is empty"<<endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        cout<<"value dequeued is : "<<temp->data<<endl;
        delete temp;
        if (front == NULL){
        rear = NULL;
        }
    }
    void peek(){
        if(isEmpty()){
            cout<<"stack underflow"<<endl;
            return;
        }
        else{
            cout<<front->data<<endl;
        }
    }
    void display(){
        if (isEmpty()){
            cout<<"queue is empty"<<endl;
            return;
        }
        Node* current = front;
        cout<<"queue elements are : ";
        while(current!=NULL){
            cout<<current->data<<" ";
            current = current->next;
        }
        cout<<endl;
    }
};
    int main(){
        queue q;
        int choice, val;
        cout<<"1.enqueue\n2.dequeue\n3.peek\n4.display\n5.exit\n";
        do{
            cout<<"enter your choice : ";
            cin>>choice;
            switch(choice){
                case 1:
                cout<<"enter value to enqueue : ";
                cin>>val;
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
                cout<<"exiting..."<<endl;
                break;
                default:
                cout<<"invalid choice"<<endl;
            }
        }while(choice!=5);
        return 0;
    }

    


