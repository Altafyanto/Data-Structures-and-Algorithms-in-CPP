// https://practice.geeksforgeeks.org/problems/ugly-numbers/0

// Time Complexity: O(n),  Auxiliary Space: O(n)

#include <iostream>
using namespace std;

unsigned long nthUglyNumber(int n)
{
    unsigned long ugly[n];
    unsigned long result = 1, i2 = 0, i3 = 0, i5 = 0;
    unsigned long next_multiple2 = 2, next_multiple3 = 3, next_multiple5 = 5;

    ugly[0] = 1;
    for (int i = 1; i < n; i++)
    {
        result = min(next_multiple2, min(next_multiple3, next_multiple5));

        ugly[i] = result;

        if (result == next_multiple2)
            next_multiple2 = ugly[++i2] * 2;

        if (result == next_multiple3)
            next_multiple3 = ugly[++i3] * 3;

        if (result == next_multiple5)
            next_multiple5 = ugly[++i5] * 5;
    }

    return result;
}

int main()
{
    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;
        cout << nthUglyNumber(n) << "\n";
    }
    return 0;
}