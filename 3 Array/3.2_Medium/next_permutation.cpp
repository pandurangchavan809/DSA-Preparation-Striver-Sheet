#include<bits/stdc++.h>
using namespace std;

// Next Permutation :-

// Input: Arr[] = {1,3,2}
// Output: {2,1,3}
// Explanation: All permutations of {1,2,3} are {{1,2,3} , {1,3,2}, {2,13} , {2,3,1} , {3,1,2} , {3,2,1}}. So, the next permutation just after {1,3,2} is {2,1,3}.
// Input : Arr[] = {3,2,1}
// Output: {1,2,3}
// Explanation : As we see all permutations of {1,2,3}, we find {3,2,1} at the last position. So, we have to return the lowest permutation.

// better approach :- STL has by default function of next_permuation

// next_permutation(A.begin(),A.end());
// return A;

// optimal solution :

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind = -1;
        int n = nums.size();
        for(int i=n-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                ind = i;
               break;
            }
        }
        if(ind == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        for(int i=n-1; i>=ind; i--){
            if(nums[i] > nums[ind]){
                swap(nums[i], nums[ind]);
                break;
            }
        }
        reverse(nums.begin() + ind+1, nums.end());
        return;
    }
};