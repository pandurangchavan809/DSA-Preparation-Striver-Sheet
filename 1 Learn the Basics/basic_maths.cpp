#include<bits/stdc++.h>
using namespace std;

// 1. given the number 'n', find out and return the number of digits present in a number.

int count(int n){
    int cnt = 0;
    while(n>0){
        int lastDigit = n%10;
        cnt = cnt + 1;
        n = n/10;
    }
    return cnt;
}

// 7. Reverse Integer : leetcode problem np - 7

class Solution {
public:
    int reverse(int x) {
        int revNum = 0;

        while (x != 0) {
            int ld = x % 10;
            x /= 10;

            // Check for overflow before multiplying
            if (revNum > INT_MAX / 10 || 
               (revNum == INT_MAX / 10 && ld > 7))
                return 0;

            if (revNum < INT_MIN / 10 || 
               (revNum == INT_MIN / 10 && ld < -8))
                return 0;

            revNum = revNum * 10 + ld;
        }
        return revNum;
    }
};


// Palimdrome Number : leetcode problem np - 9

class Solution {
public: 
    bool isPalindrome(int x) {
        if (x < 0) {
            return false; // Negative numbers are not palindromes
        }

        int original = x;
        int reversed = 0;

        while (x != 0) {
            int ld = x % 10;
            x /= 10;

            // Check for overflow before multiplying
            if (reversed > INT_MAX / 10 || 
               (reversed == INT_MAX / 10 && ld > 7))
                return false;

            reversed = reversed * 10 + ld;
        }

        return original == reversed;
    }
};



// GCD and HCF : GCD means Greatest Common Divisor and HCF means Highest Common Factor. Both are same.
// Euclidean Algorithm to find GCD of two numbers a and b.
// The Euclidean Algorithm is based on this rule:

// gcd(a, b) = gcd(b, a % b)

class Solution {
public:
    int gcd(int a, int b) {
        while (b != 0) {
            int rem = a % b;
            a = b;
            b = rem;
        }
        return a;
    }
};



// Armstrong Number : leetcode problem np - 1134

// The sum of each digit raised to the power of the number of digits equals the number itself.
// ex:- 153 = 1³ + 5³ + 3³ , 9474 = 9⁴ + 4⁴ + 7⁴ + 4⁴

class Solution {
public:
    bool isArmstrong(int n) {
        int original = n;
        int digits = 0, temp = n;

        // count digits
        while (temp > 0) {
            digits++;
            temp /= 10;
        }

        int sum = 0;
        temp = n;

        // calculate power sum
        while (temp > 0) {
            int d = temp % 10;
            sum += pow(d, digits);
            temp /= 10;
        }

        return sum == original;
    }
};


// print all divisors :

void printDivisors(int n) {
    for (int i = 1; i <= n; i++) {
        if (n % i == 0)
            cout << i << " ";
    }
}

// optimized approach to print all divisors :
void printDivisors(int n) {
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            cout << i << " ";
            if (i != n / i) {
                cout << n / i << " ";
            }
        }
    }
}



// check for prime :

class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1) return false;

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
};
