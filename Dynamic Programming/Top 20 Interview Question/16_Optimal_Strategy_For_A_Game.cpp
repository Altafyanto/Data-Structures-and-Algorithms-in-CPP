// https://practice.geeksforgeeks.org/problems/optimal-strategy-for-a-game/0

#include <iostream>
#include <cstring>
using namespace std;
int arr[101];
int DP[101][101];

int optimalStrategy(int i, int j, int sum)
{
    if (j == i + 1)
        return max(arr[i], arr[j]);

    if (DP[i][j] != -1)
        return DP[i][j];

    return DP[i][j] = sum - min(optimalStrategy(i, j - 1, sum - arr[j]), optimalStrategy(i + 1, j, sum - arr[i]));
}

int main()
{
    int t, n, sum = 0;
    cin >> t;

    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }
        memset(DP, -1, sizeof(DP));
        cout << optimalStrategy(0, n - 1, sum) << "\n";
    }
}
