#include<bits/stdc++.h>
using namespace std;

// Expression and operators

// Problem Statement: Given a string num that contains only digits and an integer target, return all possibilities to insert the binary operators '+', '-', and/or '*' between the digits of num so that the resultant expression evaluates to the target value.

// Note that operands in the returned expressions should not contain leading zeros.
// Note that a number can contain multiple digits.

/*
Input: num = "123", target = 6
Output: ["1*2*3","1+2+3"]
Explanation:  Both "1*2*3" and "1+2+3" evaluate to 6.
*/

class Solution {
public:
    vector<string> res;

    void dfs(string &num, int target, int pos, long curr, long prev, string path) {
        // If we reached the end
        if (pos == num.size()) {
            if (curr == target) {
                res.push_back(path);
            }
            return;
        }

        for (int i = pos; i < num.size(); i++) {
            // Skip numbers with leading zero
            if (i > pos && num[pos] == '0') break;

            string s = num.substr(pos, i - pos + 1);
            long val = stol(s);

            if (pos == 0) {
                // First number → no operator
                dfs(num, target, i + 1, val, val, s);
            } else {
                // Addition
                dfs(num, target, i + 1, curr + val, val, path + "+" + s);

                // Subtraction
                dfs(num, target, i + 1, curr - val, -val, path + "-" + s);

                // Multiplication (handle precedence)
                dfs(num, target, i + 1,
                    curr - prev + prev * val,
                    prev * val,
                    path + "*" + s);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        dfs(num, target, 0, 0, 0, "");
        return res;
    }
};

// Time complexity ≈ O(4ⁿ) in worst case