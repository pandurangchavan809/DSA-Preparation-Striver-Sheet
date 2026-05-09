#include<bits/stdc++.h>
using namespace std;

// Hands of Straights

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // If total cards can't be divided evenly, return false
        if (hand.size() % groupSize != 0) return false;

        // Store the frequency of each card
        map<int, int> freq;
        for (int card : hand) {
            freq[card]++;
        }

        // Create an iterator pointing to the beginning of the frequency map
        auto it = freq.begin();

        // Loop through all keys in the map
        while (it != freq.end()) {

            // Skip cards that are already used up
            if (it->second == 0) {
                ++it;
                continue;
            }

            // Store the starting card of the group
            int start = it->first;

            // Number of times we need to form this group
            int count = it->second;

            // Try to form a group of consecutive cards of size groupSize
            for (int i = 0; i < groupSize; ++i) {

                // If the current required card is missing or doesn't have enough frequency
                if (freq[start + i] < count) return false;

                // Decrease the frequency for current card
                freq[start + i] -= count;
            }

            // Move the iterator to the next element
            ++it;
        }

        // All groups formed successfully
        return true;
    }
};

/*
Time Complexity:O(N log N) , where N is the number of cards. We insert each card into a map which takes log N time per insertion. Then, for each unique card, we attempt to form a group of size groupSize, and this check involves accessing up to groupSize elements in the map, each in log N time.

Space Complexity: O(N), because we store the frequency of each unique card in a map. In the worst case, all cards are unique, so the map can hold up to N entries.
*/