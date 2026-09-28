#include <bits\stdc++.h>
using namespace std;
int evaluate (string postfix){
    stack<int> s;
    for(char c: postfix){
        if(isdigit(c)){
            s.push(c-'0');
        }
        else{ 
            int op2 = s.top();
            s.pop();
            int op1= s.top();
            s.pop();
            int result;
            switch(c){ 
                case '+':
                    result = op1 + op2;
                    break;
                case '-':
                    result = op1 - op2;
                    break;
                case '*':
                    result = op1 * op2;
                    break;
                case '/':
                    result = op1 / op2;
                    break;
                case '^':
                    result = pow(op1,op2);
                    break;
                case '%':
                    result = op1 % op2;
                    break;  
            } 
            s.push(result);
        }
    }
    return s.top();
 
int main(){
    string postfix;
    cout<<"Enter the postfix equation\n";
    cin>>postfix;    
    cout<<"The result of the postfix equation is "<<evaluate(postfix)<<endl;
    return 0;

}