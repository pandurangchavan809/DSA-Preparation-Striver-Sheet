#include<bits/stdc++.h>
using namespace std;

// Sum of Beauty of all substring

// Problem Statement: The beauty of a string is defined as the difference between the frequency of the most frequent character and the least frequent character (excluding characters that do not appear) in that string.

// Given a string s, return the sum of beauty values of all possible substrings of s.

// Examples
// Example 1:
// Input:
//  s = "xyx"
// Output:
//  1
// Explanation:
//  The substrings with non-zero beauty are:
// "xyx" → frequencies: x:2, y:1 → beauty = 2 - 1 = 1
// "xy" → x:1, y:1 → beauty = 0
// "yx" → y:1, x:1 → beauty = 0
// "x" or "y" → beauty = 0
// Total sum = 1 (from "xyx") = 1

// Example 1:

// Input: s = "aabcb"
// Output: 5
// Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.

// Example 2:

// Input: s = "aabcbaa"
// Output: 17

// Algorithm :

// Loop through all substrings of the string.
// Maintain a frequency map of characters for each substring.
// For each substring:
// Find the most frequent character's count.
// Find the least frequent non-zero character's count.
// Calculate the difference between the two counts.
// Add the difference to the running sum.



class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int sum = 0;

        // Loop over all substrings
        for (int i = 0; i < n; i++) {
            unordered_map<char, int> freq;

            for (int j = i; j < n; j++) {
                // Increase frequency of current character
                freq[s[j]]++;

                int maxi = INT_MIN;
                int mini = INT_MAX;

                // Find max and min frequency
                for (auto it : freq) {
                    mini = min(mini, it.second);
                    maxi = max(maxi, it.second);
                }

                // Add difference to sum
                sum += (maxi - mini);
            }
        }

        return sum;
    }
};











// Time Complexity:

// Outer loop: O(n) (for each starting index)
// Inner loop: O(n) (for each ending index)
// Computing max and min for frequencies: O(26) in the worst case (since only lowercase letters), O(n^2 * 26) ≈ O(n^2) because 26 is constant.

// Space Complexity:
// Frequency map uses at most 26 characters → O(26) = O(1).
// No extra data structures apart from that.