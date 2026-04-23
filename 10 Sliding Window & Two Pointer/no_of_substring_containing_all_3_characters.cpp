#include<bits/stdc++.h>
using namespace std;

// Number of Substrings Containing All Three Characters :
/*
Given a string s consisting only of characters a, b and c.
Return the number of substrings containing at least one occurrence of all these characters a, b and c.

Example 1:
Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again).
*/

class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> lastSeen(3, -1); // for 'a', 'b', 'c'
        int count = 0;

        for (int i = 0; i < s.size(); i++) {
            // update last seen index
            lastSeen[s[i] - 'a'] = i;

            // if all characters have been seen
            if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1) {
                count += 1 + min({lastSeen[0], lastSeen[1], lastSeen[2]});
            }
        }

        return count;
    }
};

// ⏱ Complexity
// Time: O(n)
// Space: O(1)