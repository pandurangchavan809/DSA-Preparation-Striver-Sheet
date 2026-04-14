#include<bits/stdc++.h>
using namespace std;

// Return the count of prime numbers present in between each range in queries array.

// Example 2:
// Input:
//  queries = [ [1, 7], [3, 7] ]  
// Output:
//  [4, 3]  
// Explanation:
  
// The range 1 to 7 contains four prime numbers: 2, 3, 5, 7.  
// The range 3 to 7 contains three prime numbers: 3, 5, 7.
/*
For each query [L, R], calculate count = primeCount[R] - primeCount[L-1].
Return the result for each query.

Algorithm (in simple words) :

Create array isPrime[n] = true
Set:
isPrime[0] = false
isPrime[1] = false
Loop from i = 2 to √n
If isPrime[i] == true
Mark all multiples of i as false
Remaining true values = primes

*/
class Solution {
public:
    vector<int> primesInRange(vector<vector<int>>& queries) {
        
        // अगर queries empty हैं तो खाली result return करो
        if (queries.empty()) {
            return {};
        }

        // Step 1: सभी queries में से maximum value निकालो
        // ताकि sieve उतनी ही range तक बने
        int maxVal = 0;
        for (const auto& query : queries) {
            maxVal = max(maxVal, query[1]);
        }

        // Step 2: Sieve of Eratosthenes लगाओ
        // isPrime[i] = true मतलब i prime है
        vector<bool> isPrime(maxVal + 1, true);

        // 0 और 1 prime नहीं होते
        isPrime[0] = isPrime[1] = false;

        // sieve logic
        for (int p = 2; p * p <= maxVal; p++) {
            if (isPrime[p]) {
                // p के multiples को false mark करो
                for (int i = p * p; i <= maxVal; i += p) {
                    isPrime[i] = false;
                }
            }
        }

        // Step 3: prefix array बनाओ
        // primeCount[i] = 1 से i तक कितने primes हैं
        vector<int> primeCount(maxVal + 1, 0);

        for (int i = 1; i <= maxVal; ++i) {
            primeCount[i] = primeCount[i - 1];
            if (isPrime[i]) {
                primeCount[i]++;
            }
        }

        // Step 4: हर query को process करो
        vector<int> result;

        for (const auto& query : queries) {
            int start = query[0];
            int end = query[1];

            // अगर start = 0 है तो direct prefix ले लो
            if (start == 0) {
                result.push_back(primeCount[end]);
            } else {
                // range [start, end] के primes
                result.push_back(primeCount[end] - primeCount[start - 1]);
            }
        }

        return result;
    }
};

/*
==================== EXPLANATION WITH REAL EXAMPLE ====================

मान लो:
queries = { {2, 10}, {5, 15} }

Step 1: maxVal = 15

Step 2: Sieve बनाएंगे (0 to 15)

Prime numbers होंगे:
2, 3, 5, 7, 11, 13

isPrime array:
index:   0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
value:   F F T T F T F T F F F  T  F  T  F  F

Step 3: Prefix array (primeCount)

i:           0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
primeCount:  0 0 1 2 2 3 3 4 4 4 4  5  5  6  6  6

मतलब:
primeCount[10] = 4  → (2,3,5,7)
primeCount[15] = 6  → (2,3,5,7,11,13)

Step 4: Queries solve करो

Query 1: [2, 10]
= primeCount[10] - primeCount[1]
= 4 - 0 = 4

Query 2: [5, 15]
= primeCount[15] - primeCount[4]
= 6 - 2 = 4

Final Output:
{4, 4}

======================================================================

TIME COMPLEXITY:
- Sieve: O(n log log n)
- Queries: O(q)

SPACE COMPLEXITY:
- O(n)

======================================================================
*/