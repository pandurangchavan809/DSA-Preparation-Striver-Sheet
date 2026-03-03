#include<bits/stdc++.h>
using namespace std;

// Check if two strings are anagrams of each other :

// --> Anagram of the string are all the possible permutations of the string.

// LeetCode-242: Valid Anagram
// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// Example 1:

// Input: s = "anagram", t = "nagaram"
// Output: true

// Example 2:

// Input: s = "rat", t = "car"
// Output: false

// Algorithm :

// First, check if the lengths of both strings are equal. If not, return false immediately as they cannot be anagrams.
// Initialize a frequency array of size 26 (for all uppercase English letters) and set all elements to 0.
// Traverse the first string and increment the frequency of each character.
// Traverse the second string and decrement the frequency of each character.
// Finally, check if all elements in the frequency array are zero. If any element is not zero, return false as the characters do not match in frequency.
// If all frequencies are zero, the strings are anagrams and the function returns true.


class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;

        int freq[26]={0};

        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']++;      // letter of s and t are in lower case and freq limit is 26 so we use small "a" instead of 'A'
        }

        for(int i=0;i<t.length();i++){
            freq[t[i]-'a']--;
        }

        for(int i=0;i<26;i++){
            if(freq[i] != 0){
                return false;
            }
        } 
        
        return true;
    }
};


// Time Complexity: O(N), where N is the length of the strings. Each string is traversed once, and the frequency array is checked in constant time (26 iterations).

// Space Complexity: O(1), as a fixed-size array of 26 elements is used regardless of the input size.