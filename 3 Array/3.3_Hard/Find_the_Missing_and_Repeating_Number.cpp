#include<bits/stdc++.h>
using namespace std;

// 
/*
Algorithm :

- First, calculate the sum of all elements in the given array, denoted as S, and the sum of natural numbers from 1 to N, denoted as Sn. The formula for Sn is (N * (N + 1)) / 2.
- Now calculate S - Sn. This gives us X - Y, where X is the repeating number and Y is the missing number.
- Next, calculate the sum of squares of all elements in the array, denoted as S2, and the sum of squares of the first N numbers, denoted as S2n. The formula for S2n is (N * (N + 1) * (2N + 1)) / 6.
- Now calculate S2 - S2n. This gives us X2 - Y2.
- From the equations S - Sn = X - Y and S2 - S2n = X2 - Y2, we can compute X + Y by the formula (S2 - S2n) / (S - Sn).
- Using the values of X + Y and X - Y, we can solve for X and Y through simple addition and subtraction.
- Finally, return the values of X (the repeating number) and Y (the missing number).
*/


vector<int> findMissingRepeatingNumbers(vector<int> a){
    long long n = a.size();
    // S - Sn = x - y
    // S2 - S2N
    long long SN = (n * (n+1)) / 2;
    long long S2N = (n * (n+1) * (2*n+1)) / 6;
    long long S = 0, S2 = 0;
    for (int i=0; i<n;i++){
        S += a[i];
        S2 += (long long)a[i] * (long long)a[i];
    }
    long long val1 = S - SN;     // x - y
    long long val2 = S2 - S2N;
    val2 = val2 / val1;     // x + y
    long long x = (val1 + val2) / 2;
    long long y = x - val1;
    return {(int)x, (int)y};
}

