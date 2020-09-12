// https://practice.geeksforgeeks.org/problems/nth-catalan-number/0

#include <iostream>
using namespace std;

//Here in this question long is not working, so we have installed boost library for Big Integer type like int_256
long nthCatalanNumber(int n)
{
    long catalan[n + 1];

    catalan[0] = catalan[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        catalan[i] = 0;

        for (int j = 0; j < i; j++)
            catalan[i] += catalan[j] * catalan[i - j - 1];
    }
    return catalan[n];
}

int main()
{
    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;
        cout << nthCatalanNumber(n) << "\n";
    }
    return 0;
}
