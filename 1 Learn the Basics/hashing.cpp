// Hashing | Maps | Time Complexity | Collisions | Division Rule of Hashing | Strivers A2Z DSA Course

// Hashing : prestoring and fetching when required
// in int main function we can't declare the array size above 10^6 as after that a segmentation error.
// but if it is declared globally 10^7 later that we have another methods to use.  Maps --> hash map, undefined map


# include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }

    // precompute
    int hash[13]={0};
    for(int i=0;i<n;i++){
        hash[arr[i]] += 1;
    }

    int q;
    cin>>q;
    while(q--){
        int number;
        cin>>number;
        //fetch
        cout<<hash[number]<<endl;
    }
    return 0;
}



// for string :

// to get index we use ASCII values as a=97 and z=122....to store index = 'a'-'f' = 5 as [a] = 'a' - 'a' = 0, b=1, same on.... for Upper Case use 'A'.
int main(){
    string s;
    cin>>s;

    // pre compute
    int hash[26] = {0};
    for(int i=0; i<s.size();i++){
        hash[s[i] - 'a']++;
    }

    int q;
    cin>>q;
    while(q--){
        char c;
        cin>> c;
        // fetch
        cout<< hash[c-'a']<<endl;
    }
    return 0;
}


// Mapas :  map<int, int>mpp; ... map<long, long>mbb; depending on the length we use int, long, long long.
// unordered_map<int, int>mpp;


int main(){

}

// Collisions and Division rule of hasing :

