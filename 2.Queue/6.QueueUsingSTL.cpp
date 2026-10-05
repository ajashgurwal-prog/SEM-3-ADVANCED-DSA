#include <iostream>
#include <queue>
using namespace std;
int main(){
    queue<int> q;
    q.push(1);
    q.push(3);
    q.push(7);
    cout << "front element: " << q.front() << endl;
    cout << "back element: " << q.back() << endl;
    q.pop();
    cout << "front element after pop: " << q.front() << endl;
    return 0;

}