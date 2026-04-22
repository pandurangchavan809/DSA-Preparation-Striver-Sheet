#include <bits/stdc++.h>
using namespace std;

// Celebrity Problem

// function to find the index of celebrity
int celebrity(vector < vector<int> & M)
{
    // size of given matrix
    int n = M.size();

    // Top and Down pointers
    int top = 0, down = n - 1;

    // traverse for all the people
    while (top < down)
    {

        /* If top knows down,
        it can not be a celebrity */
        if (M[top][down] == 1)
        {
            top = top + 1;
        }

        /* If down knowns top,
        it can not be a celebrity */
        else if (M[down][top] == 1)
        {
            down = down - 1;
        }

        /* If both does not know each other,
        both cannot be the celebrity */
        else
        {
            top++;
            down--;
        }
    }

    // Return -1 if no celebrity is found
    if (top > down)
        return -1;

    /* Check if the person pointed
    by top is celebrity */
    for (int i = 0; i < n; i++)
    {
        if (i == top)
            continue;

        // Check if it is not a celebrity
        if (M[top][i] == 1 || M[i][top] == 0)
        {
            return -1;
        }
    }
    // return the index of celebrity
    return top;
}
