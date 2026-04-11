#include<bits/stdc++.h>
using namespace std;

// Divide two numbers without multiplication and division

class Solution {
public:
    int divide(int dividend, int divisor)
    {
        // Edge case: overflow
        // INT_MIN = -2^31, dividing by -1 would exceed INT_MAX
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Determine sign of result
        // true if both have same sign, false otherwise
        bool sign = (dividend >= 0) == (divisor >= 0);

        // Convert both numbers to positive using long long
        // to avoid overflow (important for INT_MIN)
        long long n = llabs((long long)dividend);
        long long d = llabs((long long)divisor);

        long long ans = 0; // stores final quotient

        // Main loop: subtract multiples of divisor from dividend
        while(n >= d)
        {
            int i = 0;

            // Find largest power of 2 such that:
            // (d * 2^i) <= n
            while((d * (1LL << i)) <= n)
                i++;

            // Add corresponding power of 2 to answer
            ans += (1LL << (i - 1));

            // Reduce n by that large chunk
            n -= d * (1LL << (i - 1));
        }

        // Apply sign and return
        return sign ? ans : -ans;
    }
};