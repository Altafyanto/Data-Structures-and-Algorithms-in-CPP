// https://practice.geeksforgeeks.org/problems/ncr/0

// Time Complexity: O(n),  Auxiliary Space: O(n)

#include <iostream>
using namespace std;

//First refer Pascal triangle
int binomialCoefficient(int n, int r)
{
    int coeff[n + 1][r + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= min(i, r); j++) //min(i, r) so that it doesnt go out of bound
        {
            if (j == 0 || j == i)
                coeff[i][j] = 1;
            else
                coeff[i][j] = coeff[i - 1][j - 1] + coeff[i - 1][j];

            coeff[i][j] %= 1000000007;
        }
    }
    return coeff[n][r];
}

int main()
{
    int t, n, r;
    cin >> t;

    while (t--)
    {
        cin >> n >> r;
        (n < r) ? cout << "0\n" : cout << binomialCoefficient(n, r) << "\n";
    }
    return 0;
}