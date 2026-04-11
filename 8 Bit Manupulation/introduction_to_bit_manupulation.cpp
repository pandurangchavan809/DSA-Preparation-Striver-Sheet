#include<bits/stdc++.h>
using namespace std;

// Introduction to Bit Manipulation :

// decimal to binary :-

string count2binary(int x){
    string res = "";
    while(x > 0){
        if(x % 2 == 1) res += '1';
        else res += '0';
        x = x / 2;
    }
    reverse(res.begin(), res.end());
    return res;
}

int binary2decimal(string s){
    int result = 0;
    for(char c : s){
        result = result * 2 + (c - '0');
    }
    return result;
}

int main(){
    string p = count2binary(13);
    string s = "1101";
    cout <<"decimal "<< binary2decimal(s)<<endl;
    cout <<"binary "<< p << endl;
    return 0;
}