//Question:- (https://leetcode.com/explore/featured/card/recursion-i/255/recursion-memoization/1662/)

//Time Complexity - O(2^N), Space Complexity O(1)(Ignoring internal stack memory for function calls)
class Solution
{
public:
    int climbStairs(int n)
    {
        if(n <= 2)
        return n;
        
        //Either climb 1 or 2 steps
        return climbStairs(n-1) + climStairs(n-2);
    }
};

//Using DP Time Complexity - O(N), Space Complexity O(1)
class Solution
{
public:
    int climbStairs(int n)
    {
        int dp[46];
        dp[1] = 1;
        dp[2] = 2;
        
        for(int i=3; i<=n; i++)
            dp[i] = dp[i-1] + dp[i-2];
            
        return dp[n];
    }
};
