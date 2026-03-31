#include<bits/stdc++.h>
using namespace std;

// Power Set: Print all the possible subsequences of the String

// Input: str = "abc"
// Output: [a, ab, abc, ac, b, bc, c]
// Explanation: Given string has 7 subsequences.
// Input: str = "aa"
// Output: [a, a, aa] 
// Explanation: Given string has 3 subsequences.

class Solution {
public:
    // Helper function to generate subsequences
    void helper(string &s, int index, string &current, vector<string> &result) {
        // Base case
        if (index == s.size()) {
            result.push_back(current);
            return;
        }

        // 1. Exclude current character
        helper(s, index + 1, current, result);

        // 2. Include current character
        current.push_back(s[index]);
        helper(s, index + 1, current, result);

        // Backtrack
        current.pop_back();
    }

    vector<string> getSubsequences(string s) {
        vector<string> result;
        string current = "";
        helper(s, 0, current, result);
        return result;
    }
};

/*
Time Complexity: O(n * 2^n)
- There are 2^n subsequences.
- Each subsequence takes O(n) time to construct.

Space Complexity:
- O(n) auxiliary space (recursion stack depth)
- O(n * 2^n) space for storing all subsequences in result
*/