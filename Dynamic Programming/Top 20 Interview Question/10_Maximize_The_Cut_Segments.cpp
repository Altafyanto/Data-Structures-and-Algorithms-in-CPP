// https://practice.geeksforgeeks.org/problems/cutted-segments/0

/*
 First Refer Unbounded Knapsack Problem.(knapsack with Duplicate items)

 Time Complexity - O(N), Space Complexity - O(N)
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, a[4];
        cin >> n;
        a[0] = 0;
        cin >> a[1] >> a[2] >> a[3];
        sort(a, a + 4);

        int t[4][n + 1];
        for (int i = 0; i <= 3; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                // if we are not given those three integers or if our total length is 0 then there will be not cut segments.
                if (i == 0 || j == 0)
                    t[i][j] = 0;

                //if any of the given length is greater than the given total length then we can't make a piece of that length so our cuts will be equal to the cuts we had after
                // cutting into length y which was less than x.
                else if (a[i] > j)
                    t[i][j] = t[i - 1][j];

                else
                {
                    
                    if (t[i][j - a[i]] == 0 && j - a[i] != 0 && t[i - 1][j] == 0)
                        t[i][j] = 0;
                    else
                        t[i][j] = max(t[i - 1][j], t[i][j - a[i]] + 1);
                }
            }
        }
        cout << t[3][n] << endl;
    }
} 
