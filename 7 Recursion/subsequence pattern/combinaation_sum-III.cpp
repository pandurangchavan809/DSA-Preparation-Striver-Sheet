#include<bits/stdc++.h>
using namespace std;

// Combination sum III :

// https://leetcode.com/problems/combination-sum-iii/description/

// Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

// ex:-
// Input: k = 3, n = 9
// Output: [[1,2,6],[1,3,5],[2,3,4]]
// Explanation:
// 1 + 2 + 6 = 9
// 1 + 3 + 5 = 9
// 2 + 3 + 4 = 9
// There are no other valid combinations.

class Solution {

private:
   // recursion function to find combinations
   void func(int sum,int last, vector<int>&nums, int k, vector<vector<int>>& ans){
    // if the sum is zero and the number of elements is k
    if(sum == 0 && nums.size() == k){
        // add the current combination to the answer
        ans.push_back(nums);
        return;
    }
    // If the sum is less than or equal to zero or the number of elements exceeds k
    if(sum <= 0 || nums.size() > k)return;

    // Iterate from the last number to 9
    if(sum <=0 || nums.size() > k) return;

    // Iterate from the last number to 9
    for(int i=last; i<=9; i++){
        // if the sum number is less than or equal to the sum 
        if(i <= sum){
            // add the number is less than or equal to the sum 
            nums.push_back(i);
            // recursion call with updated sum and next number
            func(sum-i, i+1, nums, k, ans);
            // remove the last number to backtrack
            nums.pop_back();
        }else {
            // if the number is greater than the sum, break the loop
            break;
        }
    }
   }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int>nums;
        // call the recursion function with initial parameters
        func(n,1,nums,k,ans);
        return ans;
    }
};



// Time Complexity: O(2^9 * k), due to the exploration of all subsets of the set {1, 2, ..., 9}..

// Space Complexity: O(k), where k is the number of elements in the combination. This is due to the space used by the recursive call stack and the storage of valid combinations.