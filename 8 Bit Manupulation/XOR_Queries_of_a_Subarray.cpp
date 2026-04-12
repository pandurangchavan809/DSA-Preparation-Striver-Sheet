// You are given an array arr of positive integers. You are also given the array queries where queries[i] = [lefti, righti].
// For each query i compute the XOR of elements from lefti to righti (that is, arr[lefti] XOR arr[lefti + 1] XOR ... XOR arr[righti] ).
// Return an array answer where answer[i] is the answer to the ith query.

#include<bits/stdc++.h>
using namespace std;

// XOR Queries of a Subarray

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        
        // Step 1: Build prefix XOR
        vector<int> prefix(n);
        prefix[0] = arr[0];
        
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] ^ arr[i];
        }

        // Step 2: Answer queries
        vector<int> ans;
        
        for (auto &q : queries) {
            int L = q[0], R = q[1];
            
            if (L == 0)
                ans.push_back(prefix[R]);
            else
                ans.push_back(prefix[R] ^ prefix[L - 1]);
        }
        
        return ans;
    }
};