#include<bits/stdc++.h>
using namespace std;

// Rotate Array by one places to the right
// optimal approach : TC- O(n) SC- O(1) 

vector<int> rotateArray(vector<int>&arr, int n){
    int temp = arr[0];
    for(int i=1; i<n; i++){
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;
    return arr;
}

// rotate array to left by k places

// better solution :

void leftRotate(int arr[], int n, int k){
    k = k % n; // in case k is greater than n... as rotating n times results in same array
    int temp[k];
    for(int i=0; i<k; i++){ 
        temp[i] = arr[i];
    }

    for(int i=k; i<n; i++){
        arr[i-k] = arr[i];
    }

    for(int i=n-k; i<n; i++){
        arr[i] = temp[i-(n-k)];
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    leftRotate(arr, n, k);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}



// Left rotate the aray by k places

// most optimal approach : TC- O(2n) SC- O(1)

void leftRotate(int arr[], int n, int k){
    reverse(arr, arr+k);
    reverse(arr+k, arr+n);     // arr= 0th index
    reverse(arr, arr+n);
}



