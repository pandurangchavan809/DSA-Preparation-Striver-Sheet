#include<bits/stdc++.h>
using namespace std;

// Count Good Numbers :
// Problem Statement: A digit string is considered good if the digits at even indices (0-based) are even digits (0, 2, 4, 6, 8) and the digits at odd indices are prime digits (2, 3, 5, 7).
// Given an integer n, return the total number of good digit strings of length n. As the result may be large, return it modulo 109 + 7.
// A digit string is a string consisting only of the digits '0' through '9'. It may contain leading zeros.

class Solution {
public:
    const long long MOD = 1e9 + 7;

    // Fast exponentiation (binary exponentiation)
    long long power(long long base, long long exp) {
        long long result = 1;

        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            exp /= 2;
        }

        return result;
    }

    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2; // even indices
        long long odd = n / 2;        // odd indices

        long long ans = (power(5, even) * power(4, odd)) % MOD;

        return (int)ans;
    }
};



// O(log n)  and sc - O(1)

