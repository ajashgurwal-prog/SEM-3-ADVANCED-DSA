#include <bits/stdc++.h>
using namespace std;
bool isBalanced(string str) {
    stack<char> s;
    for (char c : str) {
        if (c == '(') {
            s.push(c);
        } else if (c == ')' ) {
            if (s.empty()) return false;
            s.pop();
            
            }
        }
    
    return s.empty();
}
int main() {
    string str;
    cout <<"enter the expression:";
    cin >>str;
    if (isBalanced(str)){
        cout << "The expression is balanced\n";
    } else {
        cout << "The expression is not balanced\n";
    }
    return 0;
}