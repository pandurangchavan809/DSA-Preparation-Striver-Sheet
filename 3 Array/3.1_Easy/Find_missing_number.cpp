#include<bits/stdc++.h>
using namespace std;

// Find the missing number in array of size n containing numbers from 1 to n
// Xor is better as 10^5 elements can cause overflow in sum method while Xor is safe.
// TC - O(n) & SC - O(1)

// method 1: Using sum formula
int findMissingNumberSum(int N, vector<int> &a) {
    int total = N * (N + 1) / 2;
    int sum_of_array = accumulate(a.begin(), a.end(), 0);
    return total - sum_of_array;
}

// method 2: Using XOR
int missingNumber(vector<int>&a, int N) {
    int xor1 = 0;
    int xor2 = 0;
    int n = N-1;
    for(int i = 0; i < n; i++) {
        xor2 = xor2 ^ a[i];
        xor1 = xor1 ^ (i + 1);
    }
    xor1 = xor1 ^ N;
    return xor1 ^ xor2;
}

int main() {
    int N = 5;
    vector<int> a = {1, 2, 3, 5};
    cout << "Missing Number (Sum Method): " << findMissingNumberSum(N, a) << endl;
    cout << "Missing Number (XOR Method): " << missingNumber(a, N) << endl;
    return 0;
}

// "XOR is safer because sum method can overflow. With XOR, since a ^ a = 0, when we XOR all numbers 1 to N with all array elements, the present numbers cancel out, leaving only the missing one. Plus, XOR works on bit level which is inherently safer from overflow."