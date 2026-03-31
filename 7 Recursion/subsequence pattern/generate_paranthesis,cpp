#include<bits/stdc++.h>
using namespace std;

// Generate Paranthesis :
// Problem Statement: Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

void backtrack(string curr, int open, int close, int n, vector<string>& res) {
    if (curr.length() == 2 * n) {
        res.push_back(curr);
        return;
    }
    if (open < n) backtrack(curr + '(', open + 1, close, n, res);
    if (close < open) backtrack(curr + ')', open, close + 1, n, res);
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    backtrack("", 0, 0, n, res);
    return res;
}


// Complexity Analysis
// Time Complexity: O(2^n) (Catalan number): C(n) = (2n)! / (n!(n+1)!) is the number of valid sequences.
// Each sequence takes O(n) to build.
// So, total complexity: O(C(n) × n)

// Space Complexity: O(n) recursion depth.
// O(C(n) × n) to store results.