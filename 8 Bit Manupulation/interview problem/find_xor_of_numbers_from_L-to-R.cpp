// https://leetcode.com/problems/xor-queries-of-a-subarray/description/
// solve the above question very important and good

class Solution
{
private:
    /* function to find the xor of number from 1 to n*/
    int XORtillN(int n)
    {
        if (n % 4 == 1)
            return 1;
        if (n % 4 == 2)
            return n + 1;
        if (n % 4 == 3)
            return 0;
        return n;
    }

public:
    /* Function to find the xor of numbers from L to R*/
    int findRangeXOR(int l, int r)
    {
        return XORtillN(l - 1) ^ XORtillN(r);
    }
};


// TC - SC : O(1)