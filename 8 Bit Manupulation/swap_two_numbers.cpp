#include<bits/stdc++.h>
using namespace std;

// swap two numbers :

// Use the XOR (^) operator to swap two integers without a temporary variable.
// Set a = a ^ b. This updates a to store the XOR of both values.
// Set b = a ^ b. This changes b to the original value of a.
// Set a = a ^ b. This updates a to the original value of b.
// This technique works due to XOR properties: x ^ x = 0 and x ^ 0 = x.


// Function to swap using XOR bit manipulation
void swapXOR(int &a, int &b) {
    // Step 1: XOR a and b, store in a
    a = a ^ b;

    // Step 2: XOR new a with b, result is original a → store in b
    b = a ^ b;

    // Step 3: XOR new a with new b, result is original b → store in a
    a = a ^ b;
}