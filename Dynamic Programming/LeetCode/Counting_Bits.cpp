// https://leetcode.com/problems/counting-bits/

//Solution 1: Using Bit Manipulation
class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> ans(num + 1);
        for (int i = 0; i <= num; i++)
        {
            int sum = 0, n = i;
            while (n)
            {
                sum++;
                n &= (n - 1); //set least significant bits to zero
            }
            ans[i] = sum;
        }
        return ans;
    }
};

/*
Solution 2: Uisng __builtin_popcount()

__builtin_popcount(x) return number of bits(ones) in x.
*/
class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> ans(num + 1);
        for (int i = 0; i <= num; i++)
            ans[i] = __builtin_popcount(i);

        return ans;
    }
};

//Solution 3: Using DP
class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> ans(num + 1);

        if (num == 0)
            return ans;

        ans[0] = 0, ans[1] = 1;
        for (int i = 2; i <= num; i++)
        {
            if (i & 1)
                ans[i] = ans[i / 2] + 1;
            else
                ans[i] = ans[i / 2];
        }

        return ans;
    }
};
