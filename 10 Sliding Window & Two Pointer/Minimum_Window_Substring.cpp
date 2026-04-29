#include<bits/stdc++.h>
using namespace std;

// Minimum Window Substring :

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        vector<int> hash(256, 0);

        // Store frequency of characters in t
        for (char c : t) {
            hash[c]++;
        }

        int l = 0, r = 0;
        int count = 0;
        int minLen = INT_MAX;
        int startIndex = -1;

        while (r < s.size()) {
            // If character is useful
            if (hash[s[r]] > 0) {
                count++;
            }

            hash[s[r]]--;

            // When all characters are matched
            while (count == t.size()) {
                // Update minimum window
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    startIndex = l;
                }

                // Remove left character
                hash[s[l]]++;
                if (hash[s[l]] > 0) {
                    count--;
                }

                l++;
            }

            r++;
        }

        return startIndex == -1 ? "" : s.substr(startIndex, minLen);
    }
};


/*
⚡ Time & Space Complexity
Time: O(N + M)
Space: O(256) (constant)
*/