#include <bits/stdc++.h>
using namespace std;

// Next Smaller elements :

vector<int> nextSmallerElement(vector<int> &arr)
{
    int n = arr.size();

    // Stack to store potential next smaller elements
    stack<int> st;

    // Answer array initialized with -1
    vector<int> ans(n, -1);

    // Traverse the array from right to left
    for (int i = n - 1; i >= 0; i--)
    {

        // Pop elements from stack while they are >= current element
        while (!st.empty() && st.top() >= arr[i])
        {
            st.pop();
        }

        // If stack is not empty, top is the next smaller element
        if (!st.empty())
        {
            ans[i] = st.top();
        }

        // Push current element to stack
        st.push(arr[i]);
    }

    // Return result
    return ans;
}