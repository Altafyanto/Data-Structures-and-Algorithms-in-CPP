// https://practice.geeksforgeeks.org/problems/count-number-of-hops/0

#include<iostream>
using namespace std;

int countNumberOFHops(int n)
{
    int DP[n+1];
    
    DP[0] = 1; // if no of steps is 0 then there frog cannot jump so this is the only way.
    DP[1] = 1; // if no of steps is 1 then frog can jump only once.
    DP[2] = 2; // if no of steps is 2 then frog can either jump 1 step 2 times or 2 steps long jump once ,then it will be two ways.

    for (int i = 3; i <= n; i++)
        DP[i] = DP[i-1] + DP[i-2] + DP[i-3]; // in all other cases total no of ways to reach top will be the sum of ways for 1 step , 2 steps and 3 steps long jump.

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
