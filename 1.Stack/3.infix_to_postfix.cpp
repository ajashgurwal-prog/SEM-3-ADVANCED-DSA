#include <bits/stdc++.h>
using namespace std;
int precedence(char c){
    if (c=='^'){
        return 3;
    }
    else if (c=='*'||c=='/'||c=='%'){
        return 2;
    }
    else if (c=='+'||c=='-'){
        return 1;
    }
    else{
        return -1;
    }
}
bool isrightas(char c){
    return c=='^';
}
string intopost(string s){
    stack<char> st;
    string ans=" ";
    for(char c:s){
        if(isalnum(c)){
        ans+=c;
    }
    else if(c=='('){
        st.push(c);
    }
    else if(c==')'){
        while(!st.empty()&&st.top()!='('){
            ans+=st.top();
            st.pop();}
            if(!st.empty()){
                st.pop();
            }
        }
        else{while(!st.empty()&&((precedence(st.top())>precedence(c))
        ||(precedence(c)&&!isrightas(c)))){
            ans+=st.top();
            st.pop();
        }st.push(c);}}
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
            return ans;
        }

        
    int main(){
        string infix,postfix;
        cout<<"Enter the infix equation\n";
        cin>>infix;
        postfix = intopost(infix);
        cout<<"postfix equation is "<<postfix << endl;
        return 0;

    }
    