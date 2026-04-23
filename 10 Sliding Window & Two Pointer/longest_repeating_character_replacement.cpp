#include<bits/stdc++.h>
using namespace std;

// Longest Repeating character replacement :

// Problem Statement: Given an integer k and a string s, any character in the string can be selected and changed to any other uppercase English character. This operation can be performed up to k times. After completing these steps, return the length of the longest substring that contains the same letter.

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, maxlen = 0, maxFreq = 0;
        vector<int> freq(26, 0);

        for (int r = 0; r < s.size(); r++) {
            freq[s[r] - 'A']++;
            maxFreq = max(maxFreq, freq[s[r] - 'A']);

            // if replacements needed > k, shrink window
            while ((r - l + 1) - maxFreq > k) {
                freq[s[l] - 'A']--;
                l++;
            }

            maxlen = max(maxlen, r - l + 1);
        }

        return maxlen;
    }
};

// Time Complexity: O(n), where n is the length of the string,each character is processed at most twice once by the right pointer, once by the left. All operations inside the loop run in constant time.

// Space Complexity: O(1), constant space .Only a fixed-size frequency array (26 letters) is used, regardless of input size.
