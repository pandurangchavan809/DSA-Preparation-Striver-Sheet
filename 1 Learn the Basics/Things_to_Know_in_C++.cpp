#include <iostream>
#include<bits/stdc++.h>     // this include all the liabraries c++ have... it takes bit more time but that's ok.
using namespace std;

int main() {
    int x, y;
    cin>>x>>y;
    cout<<"Value of x: "<<x<<"and y: "<<y;
    return 0;
}


// int
int x = 10;

// long
long x = 15;

// long long
long long x = 1400000;

// float
float x = 5.6;
float y = 5;        // 5

// double
double x = 5.7787;
double y = 6;

// string and getline
int main(){
    string str;
    getline(cin, str);
    cout<<str;
    return 0;
}

// char     (0-255 as c++ but technically ASCII = 128 )

int main()
{
    char ch = 'g';
    cout<<ch;
}

// if else statement : if statement --- if-else if-else --- if{if-else}-else if-else

int main(){
    int age;
    cin>>age;
    if(age >= 18){
        cout<<"You are an adult & vote";
    }
    else if (age==18 && age>18){        // just take for && use show case
        cout<<"you still an adult & vote";
    }
    else{
        cout<<"you can't vote & not an adult";
    }
    return 0;
}

// switch statement 

// switch statement
int main(){
    int dayNum;
    cin >> dayNum;
    
    switch(dayNum){
        case 1:
            cout << "Monday - Start of work week";
            break;
        case 2:
            cout << "Tuesday - Mid week";
            break;
        case 3:
            cout << "Wednesday - Halfway there";
            break;
        case 4:
            cout << "Thursday - Almost weekend";
            break;
        case 5:
            cout << "Friday - Weekend coming";
            break;
        case 6:
            cout << "Saturday - Weekend";
            break;
        case 7:
            cout << "Sunday - Rest day";
            break;
        default:         // last executed step if above none of them execute
            cout << "Enter number between 1-7";
            break;
    }
    return 0;
}
//-------------------------------------------------------

// Arrays :-

int main(){
    int arr[5] = {10, 20, 30, 40, 50};  // array initialization
    
    for(int i = 0; i < 5; i++){         // iterate through array
        cout << arr[i] << " ";          // print each element
    }
    
    cout << "Sum: " << (10+20+30+40+50);  // calculate sum
    return 0;
}

// 2D array - Matrix :

int main(){
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};  // 3x3 matrix initialization
    
    // Print 2D array using nested loops
    for(int i = 0; i < 3; i++){         // iterate rows
        for(int j = 0; j < 3; j++){     // iterate columns
            cout << matrix[i][j] << " ";  // access element at [row][column]
        }
        cout << endl;                   // new line after each row
    }
    return 0;
}

// Array Operations

int main(){
    int arr[5] = {10, 20, 30, 40, 50};
    int n = 5;
    
    // Taking input from user
    // for(int i = 0; i < n; i++) cin >> arr[i];
    
    // Finding maximum
    int maxVal = arr[0];
    for(int i = 1; i < n; i++) 
        if(arr[i] > maxVal) maxVal = arr[i];
    cout << "Max: " << maxVal << endl;
    
    // Finding minimum
    int minVal = arr[0];
    for(int i = 1; i < n; i++) 
        if(arr[i] < minVal) minVal = arr[i];
    cout << "Min: " << minVal << endl;
    
    // Linear search
    int target = 40, index = -1;
    for(int i = 0; i < n; i++) 
        if(arr[i] == target) { index = i; break; }
    cout << (index != -1 ? "Found at: " + to_string(index) : "Not found") << endl;
    
    // Reverse array
    for(int i = 0; i < n/2; i++) 
        swap(arr[i], arr[n-1-i]);
    
    return 0;
}

// String :

int main(){
    string s = "Striver";
    
    // String length
    cout << "Length: " << s.size() << endl;
    
    // Access character
    cout << "First char: " << s[0] << endl;      // 'S'
    cout << "Last char: " << s[s.size()-1] << endl; // 'r'
    
    // Modify character
    s[s.size()-1] = 'z';       // change last char to 'z'
    cout << "Modified: " << s << endl;      // "Strivez"
    
    // Reverse string
    reverse(s.begin(), s.end());
    cout << "Reversed: " << s << endl;
    
    return 0;
}

// For Loop :

int main(){

    for(int i = 1; i <= 5; i++){
        cout << i << " ";            //prints: 1 2 3 4 5
    }
    
    // For loop with array - print all elements
    int arr[5] = {10, 20, 30, 40, 50};
    for(int i = 0; i < 5; i++) cout << arr[i] <<" ";  // prints: 10 20 30 40 50
    
    return 0;
}

// While Loop : 
// Checks condition first, then executes code repeatedly until condition becomes false
int main(){
    int i = 1;
    while(i <= 5) cout << i++ << " ";   // prints: 1 2 3 4 5
    return 0;
}

// do-while loop : 
// Executes code at least once, then checks condition to repeat
int main(){
    int i = 1;
    do{ cout << i++ << " "; }while(i <= 5);  // prints: 1 2 3 4 5
    return 0;
}


// Functions : 
// functions are set of code which perform something for you, are used to modularise code, used to increase redability, use same code multiple times.
// void -> which dose not return anything
// return 
// parameterised
// non parameterised

// void printName(string name){
//     cout <<" hey "<<name;
// }

void sum(int a,int b){
    int sum = a + b;
    cout<<sum;
}

// int main(){
//     string name;
//     cin>> name;
//     printName(name);
//     return 0;
// }

int main(){
    int a,b;
    cin>>a>>b;
    sum(a,b);
    return 0;
}

// Functions : Pass by Value and Reference
// array,vector, map, list etc.., always passed by refrence.

void byValue(int x){ x++; cout << "By value: " << x << endl; }  // copy, original unchanged
void byReference(int &x){ x++; cout << "By reference: " << x << endl; }  // original changed

int main(){
    int num = 10;
    byValue(num);           // prints: 11, num still 10
    byReference(num);       // prints: 11, num now 11
    cout << "Final: " << num << endl;  // prints: 11
    return 0;
}


// Time Complexity :
// Time complexity = number of elementary operations as a function of input size n (Big-O).
// Examples: O(1) constant, O(log n) logarithmic, O(n) linear, O(n log n), O(n^2) quadratic.

// Space Complexity :
// Space complexity = extra memory used (excluding input) as a function of n (Big-O).
// Examples: O(1) constant extra space, O(n) linear extra space.

