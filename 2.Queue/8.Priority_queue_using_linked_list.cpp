#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    int pr;
    Node* next;
 Node(int val,int priority){
    data=value;
    pr=priority;
    next=NULL;
 }
};

class prqueue{
    private:
    Node* Front;
    public:
    prqueue(){
        front=nullptr;
    }
    bool isEmpty(){
        return front==NULL;
    }
    void(int val,int priority){
        Node* newNode=new Node(val,priority);
        if(isEmpty()){
            front=newNode;
        }
        else if(newNode->pr<front->pr){
            newNode->next=front;
            front=newNode;
        }
        else{
            Node* temp=front;
            while(temp->next!=NULL&& temp->next->pr<newNode->pr){
                temp=temp->next;
            }
            newNode->next=temp->next;
            temp->next=newNode;
        }
    }
    void dequeue(){
        if (isEmpty()){
            cout<<"underflow";
            return;
        }
        Node* temp=front;
        front =front->next;
        cout<<"deleted value is:"<<temp->data;
        cout<<"deleted priority is:"<<temp->pr;
        delete temp;
    }
    void peek(){
        if (isEmpty()){
            cout<<"underflow";
            return;
        }   
        cout<<front->data;
    }
    void display(){
        if(isEmpty()){
            cout<<"undeflow";
            return;
        }
        Node*temp=front;
        while(temp!=NULL){
            cout<<temp->data<<"->"<<temp-pr<<" \n";
            temp=temp->next;;
        }
    }

};
int main(){
    int choice,value,priority;
    prqueue q;
    cout<<"1.isEmpty\n"<<"2.enqueue\n"<<"3.dequeue\n"<<"4.peek\n"<<"5.display\n"<<"6.Exit"<<
    
}