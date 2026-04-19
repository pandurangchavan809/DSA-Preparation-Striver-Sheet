#include <bits/stdc++.h>
using namespace std;

// Asteroid Collision

vector<int> asteroidCollision(vector<int> &asteroids)
{
    // size of the array
    int n = asteroids.size();

    // list implementation of stack
    vector<int> st;

    // traverse all the asteroids

    for (int i = 0; i < n; i++)
    {
        /* Push the astroids in stack if a right moving asteroid is seen */
        if (asteroids[i] > 0)
        {
            st.push_back(asteroids[i]);
        }
        else
        {
            /* Until the right moving asteroids are
                smaller in size, keep on destroying them */
            while (!st.empty() && st.back() > 0 &&
                   st.back() < abs(asteroids[i]))
            {

                // Destroy the asteroid
                st.pop_back();
            }

            /* If there is right moving asteroid
            which is of same size */
            if (!st.empty() &&
                st.back() == abs(asteroids[i]))
            {

                // Destroy both the asteroids
                st.pop_back();
            }

            /* Otherwise, if there is no left
            moving asteroid, the right moving
            asteroid will not be destroyed */
            else if (st.empty() ||
                     st.back() < 0)
            {

                // Storing the array in final state
                st.push_back(asteroids[i]);
            }
        }
        
    }
    // return the final state of asteroids
    return st;
}