// Patterns - Building Logical Thinking for DSA by Striver

/* ========== PATTERN 1: SQUARE PATTERN ==========
   * * * * *
   * * * * *
   * * * * *
   * * * * *
   * * * * *
*/
#include <iostream>
using namespace std;

void pattern1(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << "* ";
        }
        cout << "\n";
    }
}

/* ========== PATTERN 2: RIGHT TRIANGLE PATTERN ==========
   *
   * *
   * * *
   * * * *
   * * * * *
*/
void pattern2(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < i; j++) {
            cout << "* ";
        }
        cout << "\n";
    }
}

/* ========== PATTERN 3: INVERTED TRIANGLE PATTERN ==========
   * * * * *
   * * * *
   * * *
   * *
   *
*/
void pattern3(int n) {
    for(int i = n; i >= 1; i--) {
        for(int j = 0; j < i; j++) {
            cout << "* ";
        }
        cout << "\n";
    }
}

/* ========== PATTERN 4: NUMBER TRIANGLE PATTERN ==========
   1
   1 2
   1 2 3
   1 2 3 4
   1 2 3 4 5
*/
void pattern4(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << "\n";
    }
}

/* ========== PATTERN 5: PYRAMID PATTERN ==========
       *
      * *
     * * *
    * * * *
   * * * * *
*/
void pattern5(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < n - i; j++) {
            cout << " ";
        }
        for(int j = 0; j < i; j++) {
            cout << "* ";
        }
        cout << "\n";
    }
}

/* ========== PATTERN 6: DIAMOND PATTERN ==========
       *
      * *
     * * *
    * * * *
   * * * * *
    * * * *
     * * *
      * *
       *
*/
void pattern6(int n) {
    // Upper half
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < n - i; j++) cout << " ";
        for(int j = 0; j < i; j++) cout << "* ";
        cout << "\n";
    }
    // Lower half
    for(int i = n - 1; i >= 1; i--) {
        for(int j = 0; j < n - i; j++) cout << " ";
        for(int j = 0; j < i; j++) cout << "* ";
        cout << "\n";
    }
}

/* ========== PATTERN 7: HOLLOW SQUARE ==========
   * * * * *
   *       *
   *       *
   *       *
   * * * * *
*/
void pattern7(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0 || i == n-1 || j == 0 || j == n-1) {
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        cout << "\n";
    }
}

/* ========== PATTERN 8: SPIRAL PATTERN ==========
   1 2 3 4 5
   16 17 18 19 6
   15 24 25 20 7
   14 23 22 21 8
   13 12 11 10 9
   
   Logic: Move right → down → left → up (clockwise)
   Keep track of boundaries and shrink them after each direction
*/
void pattern8(int n) {
    int arr[n][n];
    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    int num = 1;
    
    while(top <= bottom && left <= right) {
        // Move RIGHT
        for(int i = left; i <= right; i++) {
            arr[top][i] = num++;
        }
        top++;
        
        // Move DOWN
        for(int i = top; i <= bottom; i++) {
            arr[i][right] = num++;
        }
        right--;
        
        // Move LEFT
        if(top <= bottom) {
            for(int i = right; i >= left; i--) {
                arr[bottom][i] = num++;
            }
            bottom--;
        }
        
        // Move UP
        if(left <= right) {
            for(int i = bottom; i >= top; i--) {
                arr[i][left] = num++;
            }
            left++;
        }
    }
    
    // Print the spiral matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

/* ========== KEY CONCEPTS FOR LOGICAL THINKING ==========
   1. LOOP NESTING: Understanding inner and outer loops
   2. BOUNDARIES: Identifying row/column boundaries
   3. SPACING: Managing spaces vs characters
   4. SYMMETRY: Recognizing patterns in shapes
   5. CONDITIONS: Using if-else for decisions
   6. ITERATION: Counting from 1 to n or n to 1
   
   Tips:
   - Identify the number of rows
   - Identify the number of columns in each row
   - Find what to print (character/number)
   - Handle spacing and line breaks
   - Always think: What changes in each row?
*/

