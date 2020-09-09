// https://practice.geeksforgeeks.org/problems/edit-distance/0

#include <iostream>
#include <string>
using namespace std;

int editDistance(string X, string Y, int m, int n)
{
    int DP[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if(i == 0)
                DP[i][j] = j;
            
            else if(j == 0)
                DP[i][j] = i;

            else if (X[i - 1] == Y[j - 1])
                DP[i][j] = DP[i - 1][j - 1];
            else
                DP[i][j] = 1 + min(DP[i - 1][j], min(DP[i][j - 1], DP[i-1][j-1]));
        }
    }

    return DP[m][n];
}

int main()
{
    int t, m, n;
    string X, Y;
    cin >> t;

    while (t--)
    {
        cin >> m >> n;
        cin >> X >> Y;

        cout << editDistance(X, Y, m, n) << "\n";
    }

    return 0;
}