#include<bits/stdc++.h>
using namespace std;

// Word search : Given an m x n grid of characters board and a string word, return true if the word exists in the grid
// https://leetcode.com/problems/word-search/description/


class Solution {
public:
// function to check if word exists in the board
    bool exist(vector<vector<char>>& board, string word) {
        // get number of rows
        int rows = board.size();
        // get number of columns
        int cols = board[0].size();

        // loop through every cell in the grid
        for(int i=0; i<rows; i++){
            for(int j = 0; j < cols; j++){
                // start DFS if first letter matches 
                if(dfs(board, word, i, j, 0)){
                    return true;
                }
            }
        }
        // if tno path found, return false
        return false;
    }

private:
    // DFS function to search for the word
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int idx){
        // if all characters matched, returned true
        if(idx == word.size()) return true;

        // check boundries and characters match 
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[idx]) return false;

        // store current characters and mark as visited 
        char temp = board[i][j];
        board[i][j] ='#';

        //explore all the four directions 
        bool found = dfs(board, word, i + 1, j, idx + 1) ||
                     dfs(board, word, i - 1, j, idx + 1) ||
                     dfs(board, word, i, j+1, idx + 1) ||
                     dfs(board, word, i, j-1, idx + 1);
        
        // restore the characters (backtracking)
        board[i][j] = temp;
        return found;

    }
};





// Time Complexity: O(m * n * 4^L),We may start from each of the m×n cells, and explore up to 4 directions for each of the L letters in the word.

// Space Complexity: O(L),Recursion depth equals the length of the word; we also modify the board in-place, so no extra space for visited tracking.