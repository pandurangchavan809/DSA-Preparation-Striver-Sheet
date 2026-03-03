#include<bits/stdc++.h>
using namespace std;

// Longest Common Prefix :

// Problem Statement: Write a function to find the longest common prefix string amongst an array of strings. If there is no common prefix, return an empty string "".

// Examples
// Example 1
// Input:
//  str = ["flower", "flow", "flight"]
// Output:
//  "fl"
// Explanation:
//  All strings in the array begin with the common prefix "fl".

// Algorithms :

// The common prefix across all strings must exist between the smallest and largest string when sorted lexicographically.
// Sorting the array helps bring these boundary strings to the extremes.
// By comparing only the first and last strings, we can determine the full common prefix shared by the entire array.
// Character-wise comparison from the beginning allows us to identify where the prefix stops.
// The point at which the characters start differing marks the end of the shared prefix.
// The portion before this mismatch is the longest common prefix among all strings.

class Solution {
public:
    // Returns the longest common prefix in a list of strings
    string longestCommonPrefix(vector<string>& str) {
        // Handle the case where input is empty
        if (str.empty()) return "";

        // Sort the strings lexicographically
        sort(str.begin(), str.end());

        // First string in sorted order
        string first = str[0];

        // Last string in sorted order
        string last = str[str.size() - 1];

        // To store the common prefix
        string ans = "";

        // Compare up to the length of the shorter string
        int minLength = min(first.size(), last.size());

        // Compare characters of first and last string
        for (int i = 0; i < minLength; i++) {
            // Stop if characters differ
            if (first[i] != last[i]) break;

            // Add matching character to answer
            ans += first[i];
        }

        // Return the longest common prefix
        return ans;
    }
};

// Time Complexity: O(N * log N + M), where N is the number of strings and M is the minimum length of a string. The sorting operation takes O(N * log N) time, and the comparison of characters in the first and last strings takes O(M) time.

// Space Complexity: O(M), as the ans variable can store the length of the prefix which in the worst case will be O(M).