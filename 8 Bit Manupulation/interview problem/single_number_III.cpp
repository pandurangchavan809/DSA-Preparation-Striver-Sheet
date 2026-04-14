#include<bits/stdc++.h>
using namespace std;

// Single Number - III  :-

// Problem Summary :
// Every element appears twice
// Except TWO elements appear once
// Find those two numbers

// -xor_all = 2's complement of xor_all

// In simple words: Flip bits + add 1

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor_all = 0;

        // Step 1: XOR all
        for (int num : nums) {
            xor_all ^= num;
        }

        // Step 2: find rightmost set bit
        // int diff = xor_all & (-xor_all);
        int diff = xor_all & (~xor_all + 1);

        int num1 = 0, num2 = 0;

        // Step 3: divide into 2 groups
        for (int num : nums) {
            if (num & diff)
                num1 ^= num;
            else
                num2 ^= num;
        }

        return {num1, num2};
    }
};


// TC - O(N) and SC - O(1)


// nums = [1,2,1,3,2,5]
// Step 1:
// xor_all = 1^2^1^3^2^5 = 3^5
// Step 2:
// diff = rightmost set bit
// Step 3:

// Split groups → get:

// 3 and 5