// https://leetcode.com/problems/min-cost-climbing-stairs/

//Solution 1: Using Recursion + Memoization (Top Down Approach)
// Time complexity - O(N), Space Complexity - O(N)

class Solution
{
public:
    int DP[1001];
    
    int minCost(vector<int> &cost, int n)
    {
        if (n < 0)
            return 0;

        if (n == 0 || n == 1)
            return cost[n];

        if (DP[n] != -1)
            return DP[n];

        return DP[n] = cost[n] + min(minCost(cost, n - 1), minCost(cost, n - 2));
    }
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        memset(DP,-1, sizeof(DP));
        return min(minCost(cost, n - 1), minCost(cost, n - 2));
    }
};

// Solution 2: Using Bottom Up Approach
// Time complexity - O(N), Space Complexity - O(1)

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        int first = cost[0], second = cost[1];

        for (int i = 2; i < n; ++i)
        {
            int curr = cost[i] + min(first, second);
            first = second;
            second = curr;
        }
        return min(first, second);
    }
};
