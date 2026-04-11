#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    // Function to check if a number is a power of two
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;  // Check if n is greater than 0 and has only one bit set
    }
};

