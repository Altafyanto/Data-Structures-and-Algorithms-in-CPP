/* 
https://leetcode.com/problems/unique-paths/

Here we have to find total number of ways to reach our target.
Time complexity - O(N*M), Space Complexity - O(N*M)
*/

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        int paths[n][m];

        //At last row we have only one way to go i.e. downward
        for (int i = 0; i < n; i++)
            paths[i][m - 1] = 1;

        //At last coloumn we have only one way to go i.e. right
        for (int j = 0; j < m; j++)
            paths[n - 1][j] = 1;

        //For rest of indexes we have two possibilities.
        for (int i = n - 2; i >= 0; i--)
            for (int j = m - 2; j >= 0; j--)
                paths[i][j] = paths[i + 1][j] + paths[i][j + 1];

        return paths[0][0];
    }
};

/*
https://leetcode.com/problems/unique-paths-ii/

Now we have some obstacles as well.
Time complexity - O(N), Space Complexity - O(N)
*/

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[0][1] = 1;
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
                if (!obstacleGrid[i - 1][j - 1])
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        return dp[m][n];
    }
};
