#include<bits/stdc++.h>
using namespace std;

// all divisors of a given number

class Solution {
public:
    // Function to get all divisors
    vector<int> getDivisors(int N) {
        // Create a vector to store divisors
        vector<int> res;

        // Loop from 1 to square root of N
        for (int i = 1; i * i <= N; i++) {
            // Check if i divides N
            if (N % i == 0) {
                // Add i to the result
                res.push_back(i);

                // If N / i is different from i, add N / i too
                if (i != N / i) {
                    res.push_back(N / i);
                }
            }
        }

        // Return the list of divisors
        return res;
    }
};

// Time Complexity: O(sqrt(N)), we check for every number between 1 and sqaure root of N.
// Space Complexity: O(2*sqrt(N)), extra space used for storing divisors.
