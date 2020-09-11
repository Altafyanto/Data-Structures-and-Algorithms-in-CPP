/*
 https://leetcode.com/problems/longest-valid-parentheses/

 First Refer Valid Parentheses at https://leetcode.com/problems/valid-parentheses/
    
solution 1: Using Stack and isValid
Time complexity - O(N^3), space Complexity - O(N)
*/
class Solution
{
public:
    int isValid(string str)
    {
        int n = str.size();
        stack<char> s;

        for (int i = 0; i < n; i++)
        {
            if (str[i] == '(')
                s.push('(');
            else if (!s.empty() && s.top() == '(')
                s.pop();
            else
                return false;
        }
        return s.empty();
    }

    int longestValidParentheses(string s)
    {
        int n = s.size();
        if (n <= 1)
            return 0;
        int result = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 2; j < n; j += 2)
            {
                if (isValid(s.substr(i, j)))
                    result = max(result, j - i);
            }
        }
        return result;
    }
};

// Solution 2: Using DP
// Time complexity - O(N), Space complexity - O(N)
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int n = s.size(), result = 0;
        vector<int> DP(n, 0);

        for (int i = 1; i < n; i++)
        {
            if (s[i] == ')')
            {
                if (s[i - 1] == '(')
                    DP[i] = 2 + (i > 2 ? DP[i - 2] : 0);

                else if (i - DP[i - 1] > 0 && s[i - DP[i - 1] - 1] == '(')
                    DP[i] = DP[i - 1] + 2 + (i - DP[i - 1] > 2 ? DP[i - DP[i - 1] - 2] : 0);
            }
            result = max(result, DP[i]);
        }
        return result;
    }
};
