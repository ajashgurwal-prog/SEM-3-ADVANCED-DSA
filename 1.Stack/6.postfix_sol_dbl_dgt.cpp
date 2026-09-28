# include <bits/stdc++.h>
using namespace std;
int evaluatePostfix(const vector<string> tokens) {
    stack<int> s;
    for (string itr:tokens) {
        if (itr == "+" || itr == "-" || itr == "*" || itr == "/"|| itr == "^"|| itr == "%") {
            int op2 = s.top(); s.pop();
            int op1 = s.top(); s.pop(); 
            if (itr == "+") s.push(op1 + op2);
            else if (itr == "-") s.push(op1 - op2);
            else if (itr == "*") s.push(op1 * op2);
            else if (itr == "/") s.push(op1 / op2);
            else if (itr == "^") s.push(pow(op1, op2));
            else if (itr == "%") s.push(op1 % op2);
        } else {
            s.push(stoi(itr));
        }
    }
    return s.top();
}

int main() {
    string postfix;
    cout<< "enter the postfix expression:";
    getline(cin,postfix);
    stringstream ss(postfix);
    string token;
    vector<string> tokens;
    while (ss >> token) {
        tokens.push_back(token);
    }   
    cout<< evaluatePostfix(tokens);
    return 0;
}