#include<bits/stdc++.h>
using namespace std;

// LeetCode-8 : String to Integer (atoi)

// Steps to Implement: 
// 1. First, ignore any leading whitespace characters ' ' until the first non-whitespace character is found.
// 2. Check the next character to determine the sign. If it’s a '-', the number should be negative. If it’s a '+', the number should be positive. If neither is found, assume the number is positive.
// 3. Read the digits and convert them into a number. Stop reading once a non-digit character is encountered or the end of the string is reached. Leading zeros should be ignored during conversion.
// 4. The result should be clamped within the 32-bit signed integer range: [-2147483648, 2147483647]. If the computed number is outside this range, return -2147483648 if the number is less than -2147483648, or return 2147483647 if the number is greater than 2147483647.
// 5. Finally, return the computed number after applying all the above steps.

// Example 1:
// Input:
//  s = " -12345"  
// Output:
//  -12345  
// Explanation:
  
// Ignore leading whitespaces.  
// The sign '-' is encountered, indicating the number is negative.  
// Digits 12345 are read and converted to -12345.


class Solution {
public:
    int myAtoi(string s) {
        int i = 0, sign = 1;
        long long num = 0;
        int n = s.size();

        // Skip leading spaces
        while(i < n && s[i] == ' ') i++;

        // Check sign safely
        if(i < n && (s[i] == '+' || s[i] == '-')){
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Convert digits
        while(i < n && isdigit(s[i])){
            num = num * 10 + (s[i] - '0');

            // Clamp overflow
            if(sign * num > INT_MAX) return INT_MAX;
            if(sign * num < INT_MIN) return INT_MIN;

            i++;
        }

        return sign * num;
    }
};



// Time Complexity: O(n) since each character is processed once.

// Space Complexity: O(1) 