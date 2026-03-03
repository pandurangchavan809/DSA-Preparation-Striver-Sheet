#include<bits/stdc++.h>
using namespace std;

// Longest Palindromic Substring

// Given a string s, return the longest palindromic substring in s.

// Example 1:

// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.
// Example 2:

// Input: s = "cbbd"
// Output: "bb"
 

// Constraints:
// 1 <= s.length <= 1000
// s consist of only digits and English letters.




class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n <= 1) return s; 

        int start = 0;        // where longest palindrome starts
        int maxLen = 1;       // at least every single letter is a palindrome

        // Function to expand around the center
        auto expand = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }

            // When loop stops, left and right are one step beyond palindrome
            int length = right - left - 1;

            if (length > maxLen) {
                maxLen = length;
                start = left + 1;
            }
        };

        // Try each index as the center
        for (int i = 0; i < n; i++) {
            expand(i, i);       // Odd length palindromes (center at i)
            expand(i, i + 1);   // Even length palindromes (center between i and i+1)
        }

        return s.substr(start, maxLen);
    }
};

