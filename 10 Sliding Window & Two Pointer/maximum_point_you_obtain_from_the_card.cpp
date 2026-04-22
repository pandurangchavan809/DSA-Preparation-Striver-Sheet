#include<bits/stdc++.h>
using namespace std;

// Problem Statement: Given N cards arranged in a row, each card has an associated score denoted by the cardScore array. Choose exactly k cards. In each step, a card can be chosen either from the beginning or the end of the row. The score is the sum of the scores of the chosen cards.

// Maximum point you can obtain from cards

int maxScore(vector<int>& cardPoints, int k){
    // get the total number of cards
    int n = cardPoints.size();

    // calculate initial sum by picking first k cards from the front
    int total = 0;
    for(int i = 0; i<k;++i){
        total += cardPoints[i];
    }

    // store current sum as maxscore
    int maxpoints = total;

    // move the window from front to back k times
    for(int i=0; i<k; ++i){
        // substract card from front
        total -= cardPoints[k-1-i];

        // add card from back
        total += cardPoints[n - 1 - i];

        // update maxscore if needed 
        maxpoints = max(maxpoints, total);
    }
    return maxpoints;
}

// O(K+K ) ~= O(K) && O(1)