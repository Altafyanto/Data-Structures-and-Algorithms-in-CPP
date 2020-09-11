// https://leetcode.com/problems/count-square-submatrices-with-all-ones/

class Solution
{
public:
    int countSquares(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        if(m == 0)
        return 0;

        int dp[m][n];

        //Initialize row
        for (int i = 0; i < n; i++)
            dp[0][i] = matrix[0][i];

        //Initialize colun
        for (int i = 1; i < m; i++)
            dp[i][0] = matrix[i][0];

        //Buid Table
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if(matrix[i][j] == 1)
                dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]));
                else
                dp[i][j] = 0;
            }   
        }

        int result = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                result += dp[i][j];
        
        return result;
    }
};

/*
 https://practice.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix/0

 In this question you have to find largest square submatrix with all ones.

 Solution will be maximum in our above dp table.
 */
