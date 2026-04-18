#include<bits/stdc++.h>
using namespace std;

// Next Greater Element Using Stack

// func to find next greater elements
vector<int> nextGreater(vector<int>& nums){
    // stack to store elements
    stack<int> st;

    // result array of same size
    int n = nums.size();
    vector<int> res(n);

    // tranverse from right to left 
    for(int i = n-1; i>=0; i--){

        //pop all smaller or equal elements
        while(!st.empty() && st.top() <= nums[i]){
            st.pop();
        }

        // if stack is empty, no greater elements
        if(st.empty()) res[i] = -1;

        // else top of stack is answer
        else res[i] = st.top();

        st.push(nums[i]);
    }

    // return the result 
    return res;
}

// O(N)  &  O(N)