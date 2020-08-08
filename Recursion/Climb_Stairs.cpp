//Time Complexity - O(2^N) 
class Solution
{
public:
    int climbStairs(int n)
    {
        if(n <= 2)
        return n;
        
        return climbStairs(n-1) + climStairs(n-2);
    }
};

//Using DP Time Complexity - O(N) 
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