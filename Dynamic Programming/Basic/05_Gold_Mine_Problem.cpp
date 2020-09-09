// https://practice.geeksforgeeks.org/problems/gold-mine-problem/0

#include <iostream>
#include <cstring>
using namespace std;
int table[21][21];
int gold[21][21];

int maxGold(int n, int m)
{
    memset(table, 0, sizeof(table));
    for (int col = m-1; col >= 0; col--)
    {
        for (int row = 0; row < n; row++)
        {
            //we can go right iff we are not at the last column
            int right = (col == m-1) ? 0 : table[row][col+1];

            //we can go right_up iff we are not at the last column or first row
            int right_up = (row == 0 || col == m-1) ? 0 : table[row-1][col+1];

            //we can go right_down iff we are not at the last column or last row
            int right_down = (row == n-1 || col == m-1) ? 0 : table[row+1][col+1];

            //we will take the max from right, right_up, right_down
            table[row][col] = gold[row][col] + max(right, max(right_down, right_up));
        }
    }

    //Answer will be the maximum gold in first column
    int ans = table[0][0];
    for (int i = 1; i < n; i++)
        ans = max(ans, table[i][0]);

    return ans;
    
}

int main()
{
    int t, n, m;
    cin >> t;

    while (t--)
    {
        cin >> n >> m;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> gold[i][j];
        
        cout << maxGold(n, m) << "\n";
    }
    return 0;
}