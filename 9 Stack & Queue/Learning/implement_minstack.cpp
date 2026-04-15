#include<bits/stdc++.h>
using namespace std;

// Implement MinStack :
// Problem Statement: Design a stack that supports the following operations in constant time: push, pop, top, and retrieving the minimum element.

class MinStack {
private:
    // Initialize a stack (use long long to avoid overflow)
    stack<long long> st;
    
    // To store the minimum value
    long long mini;

public:
    
    // Empty Constructor
    MinStack() {
    }
    
    // Method to push a value in stack
    void push(int val) {
        
        long long value = val; // convert to long long
        
        // If stack is empty
        if(st.empty()) {
            // Update the minimum value
            mini = value;
            
            // Push current value
            st.push(value);
            return;
        }
        
        // If value is greater than minimum
        if(value > mini) {
            st.push(value);
        }
        else {
            // Push encoded value
            st.push(2 * value - mini);
            
            // Update minimum
            mini = value;
        }
    }
    
    // Method to pop a value from stack
    void pop() {
        // Base case
        if(st.empty()) return;
        
        // Get the top
        long long x = st.top();
        st.pop();
        
        // If encoded value
        if(x < mini) {
            // Restore previous minimum
            mini = 2 * mini - x;
        }
    }
    
    // Method to get the top of stack
    int top() {
        // Base case
        if(st.empty()) return -1;
        
        // Get the top
        long long x = st.top();
        
        // If normal value
        if(x > mini) return (int)x;
        
        // Otherwise return minimum
        return (int)mini;
    }
    
    // Method to get the minimum in stack
    int getMin() {
        // Return minimum
        return (int)mini;
    }
};