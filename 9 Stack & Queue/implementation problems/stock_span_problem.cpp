#include<bits/stdc++.h>
using namespace std;

// Stock span problem :

// Problem Statement: Given an array arr of size n, where each element arr[i] represents the stock price on day i. Calculate the span of stock prices for each day.

// The span Sᵢ for a specific day i is defined as the maximum number of consecutive previous days (including the current day) for which the stock price was less than or equal to the price on day i.

//  n = 7, arr = [120, 100, 60, 80, 90, 110, 115]
// Output:
//  1 1 1 2 3 5 6

class StockSpanner {
private:
    stack<pair<int, int>> st; // {price, span}

public:
    StockSpanner() {
    }
    
    int next(int price) {
        int span = 1;
        
        // Merge spans of all smaller/equal prices
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        
        // Push current price with its span
        st.push({price, span});
        
        return span;
    }
};


// O(N)  & O(N)
