#include <iostream>
#include <stack>
using namespace std;
void decimalToBinary(int n) {
    stack<int> s;
    if (n == 0) {
        cout << "Binary representation: 0" << endl;
        return;
    }
    while (n > 0) {
        s.push(n % 2);
        n /= 2;
    }
    cout << "Binary representation: ";
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
    cout << endl;
}
int main() {
    int n;
    cout << "Enter a decimal number: ";
    cin >> n;
    decimalToBinary(n);
    return 0;
}