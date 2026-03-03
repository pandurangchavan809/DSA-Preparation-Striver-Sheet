#include<bits/stdc++.h>
using namespace std;

// Pascal Triangle

/*
Input: N = 5, r = 5, c = 3 
Output: Element at position (r, c): 6
N-th row of Pascal’s triangle: 1 4 6 4 1
First n rows of Pascal’s triangle:
1 
1 1 
1 2 1 
1 3 3 1 
1 4 6 4 1  
Explanation: Pascal triangle for first 5 rows is shown above.
Input: N = 1, r = 1, c = 1
Output: Element at position (r, c): 1
N-th row of Pascal’s triangle: 1
First n rows of Pascal’s triangle:
1  
Explanation: N = 1 is the base case fof a pascal's triangle.
*/

// 1. given R & C tell the element at that place :-
// using n!/r!(n-r)! = in optimized that formula like 7*6/2*1  for n=7 and r=2
// r-1 C c-1 = formula to find element at row r and column c

int nCr(int n, int r){
    long long res=1;
    for(int i=0;i<r;i++){
        res = res * (n-i);
        res = res / (i+1);
    }
    return res;
}

// 2. print the entire row of pascal triangle.. n=5

//    ans = 1;
// for 1st column ans = 1.. then loop print remaining
/*
for(i=1; i<n; i++){
    ans = ans*(n-i);
    ans = ans/(i)
    print(ans);
}
*/

// 3. given n. print entire pascal triangle


// for a row 
vector<int> generateRow(int row){
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1);
    for(int col=1; col<row; col++){
        ans = ans * (row-col);
        ans = ans / (col);
        ansRow.push_back(ans);
    }
    return ansRow;
}

// for entire triangle we call row function :

vector<vector<int>> pascalTraingle(int N){
    vector<vector<int>> ans;
    for(int i=1; i<=N; i++){
        ans.push_back(generateRow(i));
    }
    return ans;
}



