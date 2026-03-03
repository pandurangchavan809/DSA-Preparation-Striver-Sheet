#include<bits/stdc++.h>
using namespace std;

// Reverse Words in a String :

// Problem Statement: Given an input string, containing upper-case and lower-case letters, digits, and spaces( ' ' ). A word is defined as a sequence of non-space characters. The words in s are separated by at least one space. Return a string with the words in reverse order, concatenated by a single space.

// Examples
// Input: s = "welcome to the jungle"
// Output: "jungle the to welcome"
// Explanation: The words in the input string are "welcome", "to", "the", and "jungle". Reversing the order of these words gives "jungle", "the", "to", and "welcome". The output string should have exactly one space between each word.

// Input: s = " amazing coding skills "
// Output: "skills coding amazing"
// Explanation: The input string has leading and trailing spaces, as well as multiple spaces between the words "amazing", "coding", and "skills". After trimming the leading and trailing spaces and reducing the multiple spaces between words to a single space, the words are "amazing", "coding", and "skills". Reversing the order of these words gives "skills", "coding", and "amazing". The output string should not have any leading or trailing spaces and should have exactly one space between each word.



class Solution {
public:
    // Function to reverse the order of words 
    string reverseWords(string s) {
        // Result string to store final output
        string result = "";
        
        // Pointer starting from the last character
        int i = s.size() - 1;
        
        // Traverse string from right to left
        while (i >= 0) {
            // Skip spaces at the current position
            while (i >= 0 && s[i] == ' ') {
                i--;
            }
            
            // If pointer is out of bounds, break
            if (i < 0) break;
            
            // Mark the end of the current word
            int end = i;
            
            // Move left until a space or start of string is found
            while (i >= 0 && s[i] != ' ') {
                i--;
            }
            
            // Extract the current word
            string word = s.substr(i + 1, end - i);
            
            // Add space before appending next word if result is not empty
            if (!result.empty()) {
                result += " ";
            }
            
            // Append the word to the result
            result += word;
        }
        
        return result;
    }
};



// Time Complexity: O(N), We traverse the string once from right to left and construct the result directly without extra passes.

// Space Complexity: O(1),Ignoring the output string, no additional data structures proportional to input size are used.