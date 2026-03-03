#include<bits/stdc++.h>
using namespace std;

// Sort characters by frequency

// Problem Statement: You are given a string s. Return the array of unique characters, sorted by highest to lowest occurring characters.
// If two or more characters have same frequency then arrange them in alphabetic order.
// Examples
// Example 1:
// Input:
//  s = "tree"
// Output:
//  ['e', 'r', 't']
// Explanation:

// e → 2
// r → 1
// t → 1
// Since 'r' and 't' have the same frequency, they are sorted alphabetically → 'r' comes before 't'.


// Algorithm :

// The goal is to rank characters based on how frequently they appear in the string.
// We need a structure that can track both the character and how often it occurs.
// Sorting the characters by frequency helps surface the most significant ones first.
// To maintain consistency when frequencies match, tie-breaking is done alphabetically.
// Once sorted, the characters with non-zero occurrences form the final ranked result.



class Solution {
private:
    // Custom comparator: sort by frequency descending, then by character ascending
    static bool comparator(pair<int, char> p1, pair<int, char> p2) {
        if (p1.first > p2.first) return true;
        if (p1.first < p2.first) return false;
        return p1.second < p2.second;
    }

public:
    vector<char> frequencySort(string& s) {
        // Array to store frequency and character
        pair<int, char> freq[26];
        
        // Initialize frequency array with character labels
        for (int i = 0; i < 26; i++) {
            freq[i] = {0, i + 'a'};
        }

        // Count frequency of each character in string
        for (char ch : s) {
            freq[ch - 'a'].first++;
        }

        // Sort the frequency array using the custom comparator
        sort(freq, freq + 26, comparator);

        // Store characters with non-zero frequency
        vector<char> ans;
        for (int i = 0; i < 26; i++) {
            if (freq[i].first > 0) ans.push_back(freq[i].second);
        }

        // Return the result
        return ans;
    }
};



// Time Complexity: O(n + k log k), where n is the length of the string and k is the constant 26 for the alphabet.

// Space Complexity: O(k) , where k is the constant 26 for the frequency array.



// O(n log n)


// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         if(s.size() != t.size()) return false;

//         int freq[26] = {0};

//         for(int i = 0; i < s.size(); i++){
//             freq[s[i] - 'a']++;
//             freq[t[i] - 'a']--;
//         }

//         for(int x : freq){
//             if(x != 0) return false;
//         }

//         return true;
//     }
// };