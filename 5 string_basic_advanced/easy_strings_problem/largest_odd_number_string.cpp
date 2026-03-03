#include<bits/stdc++.h>
using namespace std;


// Largest Odd Number in a String.

// Problem Statement: Given a string s, representing a large integer, the task is to return the largest-valued odd integer (as a string) that is a substring of the given string s.
// The number returned should not have leading zero's. But the given input string may have leading zero.

// Examples
// Example 1
// Input:
//  s = "5347"
// Output:
//  "5347"
// Explanation:
//  The odd numbers formed by the given string are → 5, 3, 53, 347, 5347. The largest odd number without leading zeroes is 5347.

// Example 2
// Input:
//  s = "0214638"
// Output:
//  "21463"
// Explanation:
//  The odd numbers formed by the string are → 1, 3, 21, 63, 463, 1463, 21463. We can't use numbers starting with 0, so the largest valid odd number is 21463.


// Time Complexity: O(N), since the loop runs once through the string of length N.

// Space Complexity: O(1), as we are using only a constant amount of extra space.


class Solution {
public:
    // Returns the largest odd number substring from the given string
    string largeOddNum(string& s) {
        int ind = -1;

        // Find the last odd digit in the string
        int i;
        for (i = s.length() - 1; i >= 0; i--) {
            if ((s[i] - '0') % 2 == 1) {
                ind = i;
                break;
            }
        }

        // Skip leading zeroes up to the odd digit
        i = 0;
        while (i <= ind && s[i] == '0') i++;

        // Return substring from first non-zero to odd digit
        return s.substr(i, ind - i + 1);
    }
};