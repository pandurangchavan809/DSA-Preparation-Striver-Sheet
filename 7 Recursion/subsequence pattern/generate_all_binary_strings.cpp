#include<bits/stdc++.h>
using namespace std;

// Generate all binary strings :

// Problem Statement: Given an integer n, return all binary strings of length n that do not contain consecutive 1s. Return the result in lexicographically increasing order.

#include <bits/stdc++.h>
using namespace std;

void generate(int n, string curr, vector<string>& result) {
    // Base case: if length is n, add to result
    if (curr.length() == n) {
        result.push_back(curr);
        return;
    }

    // Always try adding '0'
    generate(n, curr + "0", result);

    // Add '1' only if previous char is not '1'
    if (curr.empty() || curr.back() != '1') {
        generate(n, curr + "1", result);
    }
}

// Time Complexity: O(2^n), since each position has 2 choices.

// Space Complexity: O(n) per recursive path (due to call stack)


// Another normal way :

