#include<bits/stdc++.h>
using namespace std;

// Check if one string is rotation of another

// Problem Statement: Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
// A shift on s consists of moving the leftmost character of s to the rightmost position. For example, if s = "abcde", then it will be "bcdea" after one shift.
// Examples
// Example 1:
// Input:
//  s = "rotation", goal = "tionrota"
// Output:
//  true
// Explanation:
//  After multiple left shifts on "rotation", we get:
//     1st shift → "otationr"
//     2nd shift → "tationro"
//     3rd shift → "ationrot"
//     4th shift → "tionrota"
//     So the goal string can be obtained by rotating the original string.

// -->
// Algorithm :

// Double the original string by joining it with itself, creating a new string like s + s.
// Look for the target string goalinside this new doubled string.
// If goal exists within the doubled string, then it's a valid rotation, return true.
// If it's not found, that means the original string cannot be rotated to match goal, return false


class Solution {
public:
    // Check if goal is a rotation of s using string doubling method
    bool rotateString(string& s, string& goal) {
        // Strings must be the same length to be rotations of each other
        if (s.length() != goal.length()) return false;
        
        // Concatenate s with itself and check if goal exists in it
        string doubledS = s + s;
        return doubledS.find(goal) != string::npos;
    }
};


// Time Complexity: O(N), because checking for a substring in s + s is linear in time.

// Space Complexity: O(N) for the space needed to store the concatenated string s + s.


