#include<bits/stdc++.h>
using namespace std;

// Prefic to Infix conversion :

string prefixToInfix(string prefix){
    stack<string> s;
    int n = prefix.size();

    // transverse the prefix expression from right to left 
    for(int i = n-1; i>=0; i--){
        char c = prefix[i];

        // if the character is an operand, push it to the stack
        if(isalnum(c)){
            s.push(string(1, c));
        }else{
            // pop two operands from the stack
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();

            // form the new infix expression and push back to stack
            s.push("("+op1+c+op2+")");
        }
    }

    // the final element in the stack is the result
    return s.top();
}

// O(N) and O(N)