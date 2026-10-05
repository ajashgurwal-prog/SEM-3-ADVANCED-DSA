#include <iostream>
using namespace std;

class PriorityQueue{
    private:
    int *arr;
    int size;
    int rear;
    
public:
    PriorityQueue(int n){
        size = n;
        arr = new int[size];
        rear = -1;
    };
    bool isEmpty(){
        return rear == -1;
    };
    bool isFull(){
        return rear == size - 1;
    };
    void enqueue(int value){
        if(isFull()){
            cout << "Queue is full" << endl;
            return;
        }
        int i= rear;
        while(i>=0 && arr[i] > value){
            arr[i+1] = arr[i];
            i--;
        }
        rear++;
        arr[i+1] = value;
        cout << "Inserted " << value << endl;
    };
    int dequeue(){
        if(isEmpty()){
            cout << "Queue is empty" << endl;
            return -1;
        }
        int item = arr[rear];
        rear=rear - 1;
        return item;
    }
    int peek(){
        if(isEmpty()){
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[rear];
    };
    void display(){
        if(isEmpty()){
            cout << "Queue is empty" << endl;
            return ;
        }
        cout << "Queue elements: ";
        for(int i=rear; i>=0; i--){
            cout << arr[i] << " ";
        }
        cout << endl;
    };
    
};
int main(){
    int n;
    cout << "Enter the size of the priority queue: ";
    cin >> n;
    PriorityQueue pq(n);
    do{
        cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\nEnter your choice: ";
        int choice;
        int value;
        cin >> choice;
        switch(choice){
            case 1:
                int value;
                cout << "Enter the value to enqueue: ";
                cin >> value;
                pq.enqueue(value);
                break;
            case 2:
                value = pq.dequeue();
                if(value != -1){
                    cout << "Dequeued: " << value << endl;
                }
            case 3:
                cout << "Peek: " << pq.peek() << endl;
                break;
            case 4:
                pq.display();
                break;
            case 5:
                exit(0);
            default:
                cout << "Invalid choice" << endl;
        }
    } while(true);
    //while true loop to keep the program running until the user chooses to exit
    
    return 0;
}
