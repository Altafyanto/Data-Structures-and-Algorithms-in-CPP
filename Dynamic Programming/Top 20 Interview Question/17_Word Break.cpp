// https://practice.geeksforgeeks.org/problems/word-break/0

#include <iostream>
#include <cstring>
#include <unordered_set>
using namespace std;

int wordBreak(unordered_set<string> &dict, string word)
{
    int size = word.size();
    
    // empty string will always be present in dictionary.
    if (size == 0)
        return 1;
    
    int DP[size + 1];
    memset(DP, 0, sizeof(DP)); //Initialize with false

    for (int i = 1; i <= size; i++)
    {
        // if any letter is not traversed yet and sustring upto that letter is present in dictionary then return 1.
        if (DP[i] == 0 && dict.find(word.substr(0, i)) != dict.end())
            DP[i] = 1;

        // if a letter is traversed before and also substing upto it is present in dictionary
        if (DP[i] == 1)
        {
            // if we reach at the last letter than it will be present in dictionary.
            if (i == size)
                return 1;

            // otherwise we will traverse from i+1 letter to size of the string and will check for the substring formed by remianing letters.
            for (int j = i + 1; j <= size; j++)
            {
                if (DP[j] == 0 && dict.find(word.substr(i, j - i)) != dict.end())
                    DP[j] = 1;

                // if we are at last letter, if substring including all letters upto last letter is present in dictionary then will return 1.
                if (j == size && DP[size] == 1)
                    return 1;
            }
        }
    }

    return 0;
}

int main()
{
    int t, n;
    cin >> t;
    unordered_set<string> dict;

    while (t--)
    {
        cin >> n;
        dict.clear();
        string word, x;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            dict.insert(x);
        }
        cin >> word;
        cout << wordBreak(dict, word) << "\n";
    }
}
