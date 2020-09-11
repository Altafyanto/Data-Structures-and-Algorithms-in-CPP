// https://leetcode.com/problems/triangle/

//Solution 1: Top Down
int minimumTotal1(vector<vector<int>> &triangle)
{
    vector<int> res(triangle.size(), triangle[0][0]);
    for (int i = 1; i < triangle.size(); i++)
    {
        for (int j = i; j >= 0; j--)
        {
            if (j == 0)
                res[0] += triangle[i][j]; // First element of row have only one child
            else if (j == i)
                res[j] = triangle[i][j] + res[j - 1]; // Last element of row have only one child
            else
                res[j] = triangle[i][j] + min(res[j - 1], res[j]); // For the rest of element will choose minimum one
        }
    }
    return *min_element(res.begin(), res.end());
}

// Solution 2: Bottom Up
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<int> DP(triangle.back());

        for (int i = n - 2; i >= 0; --i)
            for (int j = 0; j <= i; j++)
                DP[j] = triangle[i][j] + min(DP[j], DP[j + 1]);

        return DP[0];
    }
};
