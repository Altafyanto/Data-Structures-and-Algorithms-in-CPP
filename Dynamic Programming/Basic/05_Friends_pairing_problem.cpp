// https://practice.geeksforgeeks.org/problems/friends-pairing-problem/0
#include <iostream>
using namespace std;
#define mod 1000000007

long countNumberofWays(int n)
{
    long count[n + 1];

    for (int i = 1; i <= n; i++)
    {
        if (i <= 2)
            count[i] = i;
        else
            count[i] = (count[i - 1] + ((i - 1) * count[i - 2]) % mod) % mod;
    }
    return count[n];
}

int main()
{
    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;
        cout << countNumberofWays(n) << "\n";
    }
    return 0;
}
