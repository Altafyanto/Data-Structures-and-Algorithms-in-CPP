/* (https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle/0)
Question:- We are given no of eggs and no of floors . We have to find the minimum no of attempts to find the threshold floor .
Threshold floor is the first possible floor from which if we will throw the egg , it will not break.
*/

#include <iostream>
using namespace std;

// Solution 1: Using Recursion
int eggDropPuzzle(int eggs, int floors)
{
    // If there is only one floor then we will get our threshold floor only after throwing one egg , as after throwing one egg from it the egg will either break or saved.
    // If there is only one egg then we will start throwing the egg from lowermost building so that it will not break before reaching the threshold floor , 
    // so in worst case, egg will break on lowermost foor and it will be threshold floor.
    if(floors == 1 || eggs == 1)
        return floors;

    int minimum = INT_MAX;
    // We will break our floors into two parts and will check in both parts by throwing the eggs and will get attemps from both and 
    // will add one to maximum of both attemps for the middle one.
    for (int k = 1; k <= floors; k++)
    {
        int tempAns = 1 + max(eggDropPuzzle(eggs-1, k-1), eggDropPuzzle(eggs, floors-k));

        minimum = min(tempAns, minimum);
    }
    return minimum;
}

// Solution 2: Using Recursion + Memoization
int DP[11][51];
int eggDropPuzzle(int eggs, int floors)
{
    if(floors == 1 || eggs == 1)
        return floors;

    if(DP[eggs][floors] != -1)
        return DP[eggs][floors];

    int minimum = INT_MAX;
    for (int k = 1; k <= floors; k++)
    {
        int tempAns = 1 + max(eggDropPuzzle(eggs-1, k-1), eggDropPuzzle(eggs, floors-k));

        minimum = min(tempAns, minimum);
    }
    return DP[eggs][floors] = minimum;
}

int main()
{
    int t, eggs, floors;
    cin >> t;

    while (t--)
    {
        cin >> eggs >> floors;
        memset(DP, -1, sizeof(DP));//For solution 2
        cout << eggDropPuzzle(eggs, floors) << "\n";
    }
}
