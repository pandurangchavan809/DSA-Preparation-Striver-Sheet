#include<bits/stdc++.h>
using namespace std;

//  Longest Substring Without Repeating Characters :

// Given a string s, find the length of the longest substring without duplicate characters.

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // We use a vector as a hash map for ASCII characters (128 total)
        // Store the last seen index of each character, initialized to -1
        vector<int> lastIndex(128, -1);
        
        int maxLength = 0;
        int left = 0; // The start of our current window

        for (int right = 0; right < s.length(); ++right) {
            char currentChar = s[right];

            // If we've seen this character before AND it's inside our current window
            if (lastIndex[currentChar] >= left) {
                // Shrink the window by jumping 'left' to the right of the previous occurrence
                left = lastIndex[currentChar] + 1;
            }

            // Update the last seen index of the character
            lastIndex[currentChar] = right;

            // Update the maximum length found
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};

// O(N) && O(128)
