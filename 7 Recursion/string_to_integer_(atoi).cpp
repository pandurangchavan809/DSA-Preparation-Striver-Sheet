#include<bits/stdc++.h>
using namespace std;

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
            num = num * 10 + (s[i] - '0');  # this gives integer

            // Clamp overflow
            if(sign * num > INT_MAX) return INT_MAX;
            if(sign * num < INT_MIN) return INT_MIN;

            i++;
        }

        return sign * num;
    }
};