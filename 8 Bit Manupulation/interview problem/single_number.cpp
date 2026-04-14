#include<bits/stdc++.h>
using namespace std;

// Single Number - I

class Solution {
public:
    int singleNumber(vector<int>& nums){
        int ans =0;
        for(int val : nums){
                ans = ans^val;
        }
        return ans;
        
    }
};   

// nums = [4, 1, 2, 1, 2]

// ans = 0
// ans = 0 ^ 4 = 4
// ans = 4 ^ 1 = 5
// ans = 5 ^ 2 = 7
// ans = 7 ^ 1 = 6   (1 cancels)
// ans = 6 ^ 2 = 4   (2 cancels)

// Time Complexity: O(n) → one loop
// Space Complexity: O(1) → no extra memory