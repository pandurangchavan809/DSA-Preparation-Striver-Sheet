#include<bits/stdc++.h>
using namespace std;

// https://takeuforward.org/data-structure/rotate-image-by-90-degree
// Abpve Link for the Theory and logicl concept while a theory of Algorithm


// T - O(n^2) and S - O(1)

void rotateMatrix(vector<vector<int>> &mat){
    int n = mat.size();
    // Transpose   
    // O(n/2 * n/2)   // no need to rotate diagonal elements ....... 11, 22, 33 this are at position.
    // We only swap elements above the diagonal
    // The diagonal (i == j) stays the same
    // Each pair is swapped only once
    for(int i=0; i<n-1;i++){
        for(int j=i+1; j<n; j++){
            swap(mat[i][j], mat[j][i]);
        }
    }
    //reverse
    // O(N * N / 2)
    for(int i=0; i<n; i++){
        // row is mat [i]
        reverse(mat[i].begin(), mat[i].end());
    }
}