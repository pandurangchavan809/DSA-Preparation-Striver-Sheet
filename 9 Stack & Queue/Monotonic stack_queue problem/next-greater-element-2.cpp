#include<bits/stdc++.h>
using namespace std;

// Next Greater Element 2 :
// next greater element of nums[nums.length-1] is nums[0]

// element for each element in the array
vector<int> nextgreaterElements(vector<int> arr){
    int n = arr.size(); // size of the array

    // to store the next greater element s
    vector<int> ans(n);

    // stack to get elements in LIF fashion 
    stack<int> st;

    // stack traversing from the back 
    for(int i = 2*n-1; i >=0; i--){
        // get the actual index
        int ind = i % n;

        // get the current element
        int currEle = arr[ind];

        /* Pop the elements in the stack until the stack is not empty and the top element is not greater element */
        while(!st.empty() && st.top() <= currEle) {
            st.pop();
        }

        if( i < n){
            // if greater element is not found stack is empty 
            if(st.empty()){
                ans[i] = -1;

            }else{
                ans [i] = st.top();
            }
            /* Push the current element in the stack maintaining the decreasing order*/
            st.push(currEle);

        }
        // return the result
        return ans;
    }
}

// O(N)  & O(N)