// https://practice.geeksforgeeks.org/problems/count-number-of-hops/0

#include<iostream>
using namespace std;

int countNumberOFHops(int n)
{
    int DP[n+1];
    DP[0] = 1, DP[1] = 1, DP[2] = 2;

    for (int i = 3; i <= n; i++)
        DP[i] = DP[i-1] + DP[i-2] + DP[i-3];

    return DP[n];
}

int main()
{
    int t, n;
    cin >> t;

    while(t--)
    {
        cin >> n;
        cout << countNumberOFHops(n) << "\n";
    }
}