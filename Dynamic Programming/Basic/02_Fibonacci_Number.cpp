// https://practice.geeksforgeeks.org/problems/nth-fibonacci-number/0

// Time Complexity: O(n),  Auxiliary Space: O(n)

// Recursive working formulae : fib[n] = fib[n - 1] + fib[n - 2]

#include <iostream>
using namespace std;

int nthFibNumber(int n)
{
    int fib[n + 2];
    fib[0] = 0, fib[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
        fib[i] %= 1000000007;
    }

    return fib[n];
}

int main()
{
    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;
        cout << nthFibNumber(n) << "\n";
    }
    return 0;
}