// Functions and Recursion in C++

#include <iostream>
using namespace std;

// Function to calculate factorial of a number using recursion
int factorial(int n) {
    if (n <= 1) // Base case
        return 1;
    else
        return n * factorial(n - 1); // Recursive case
}   

int main() {
    int number;
    cout << "Enter a positive integer: ";
    cin >> number;

    if (number < 0) {
        cout << "Factorial is not defined for negative numbers." << endl;
    } else {
        int result = factorial(number);
        cout << "Factorial of " << number << " is " << result << endl;
    }

    return 0;
}

// This program demonstrates the use of functions and recursion in C++. It defines a recursive function to calculate the factorial of a given positive integer.

// A void function does not return a value. It performs an action but does not send any value back to the caller...means nothing is returned to the calling function. For example:
void greet() {
    cout << "Hello, welcome to the C++ programming world!" << endl;
}

void exampleVoidFunction() {
    greet(); // Calling the void function
}
// In this example, the greet function is a void function that prints a welcome message to the console. It does not return any value.



// A function with parameters takes input values to perform its task. For example:
int add(int a, int b) {
    return a + b; // Returns the sum of a and b
}

// Parameterized and functional recursion example :
int power(int base, int exponent) {
    if (exponent == 0)
        return 1;
    else
        return base * power(base, exponent - 1);
}
// In this example, the add function takes two integer parameters and returns their sum. The power function calculates the power of a base raised to an exponent using recursion.
// The power function demonstrates functional recursion, where the function calls itself with modified parameters until it reaches the base case.


// problems to practice:

// 1. reverse an array 

void f(int i, int n, int arr[]) {
    if (i >= n / 2) return; // base case
    swap(arr[i], arr[n - i - 1]);
    f(i + 1, n, arr); // recursive call
}   

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    f(0,n,arr);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}



// 2. check if a string is palindrome using recursion

bool isPalindrome(string str, int left, int right) {
    if (left >= right) // base case
        return true;
    if (str[left] != str[right])
        return false;
    return isPalindrome(str, left + 1, right - 1); // recursive call
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    if (isPalindrome(str, 0, str.length() - 1))
        cout << str << " is a palindrome." << endl;
    else
        cout << str << " is not a palindrome." << endl;
    return 0;
}

// Multiple Recursion call :
// When a function calls itself more than once, it's called multiple recursion. 
// For example, calculating Fibonacci numbers:
int fibonacci(int n) {
    if (n <= 1) // base case
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2); // multiple recursive calls
}

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;
    cout << "Fibonacci of " << n << " is " << fibonacci(n) << endl;
    return 0;
}

// In this example, the fibonacci function calls itself twice to calculate the Fibonacci number for a given n. This leads to an exponential number of calls for larger n, demonstrating multiple recursion.                  


