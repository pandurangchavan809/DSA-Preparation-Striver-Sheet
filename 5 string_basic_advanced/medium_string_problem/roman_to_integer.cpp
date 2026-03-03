#include<bits/stdc++.h>
using namespace std;

// Roman Numerals to Integer

// Problem Statement: Roman numerals are represented by seven different symbols: I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1000
// For example: 2 is written as II, 12 is written as XII, 27 is written as XXVII.
// Roman numerals are usually written largest to smallest from left to right. But in six special cases, subtraction is used instead of addition:
// I before V or X → 4 and 9,
// X before L or C → 40 and 90,
// C before D or M → 400 and 900
// Given a Roman numeral, convert it to an integer.

// Examples
// Example 1:
// Input:
//  s = "LVIII"
// Output:
//  58
// Explanation:
//  L = 50, V= 5, III = 3.

// Algorithm :

// Understand that Roman numerals are generally written in descending order of value, and their values are added.
// However, when a smaller value appears before a larger one, it indicates subtraction instead of addition.
// To handle this, scan the string from left to right and compare each character with the one after it.
// If the current symbol is smaller than the next, treat it as a subtractive pair.
// Otherwise, treat the symbol as a standalone value and add it normally.
// The final character is always added since there's nothing after it to compare.

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> value = {
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };
        
        int result = 0;
        for (int i = 0; i < s.length(); i++) {
            // If next roman numeral is larger, subtract current value
            if (i + 1 < s.length() && value[s[i]] < value[s[i + 1]]) {
                result -= value[s[i]];
            } 
            else {
                result += value[s[i]];
            }
        }
        return result;
    }
};



// Time Complexity: O(n), where n is the length of the input string since we traverse the string once.
// Space Complexity: O(1), since we use a fixed-size map for Roman numerals.