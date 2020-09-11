// https://leetcode.com/problems/divisor-game/

//Solution 1: Using DP
class Solution {
public:
    bool divisorGame(int N) {
        bool dp[N+1];
        
        // initialising DP matrix with all falses.
        memset(dp,false,sizeof(dp));
        
        // We don't need to check for n < 2 as alice is starting first then in these cases only alice will win.
        for(int i=2;i<=N;i++)
        {
            bool temp = false;
            
            // We only need to check upto root of i because if bob lose upto i/2 then he will loose the game.
            for(int j=1;j*j<=i;j++)
            {
                // if after choosing j upto root of i it is divisible by j and and after replacing the value with i-j DP is giving false 
                // means Bob is not able to make a move so in that case alice will win.
                if(i%j==0)
                {
                    if(dp[i-j]==false)
                    {
                      temp = true;
                      break;
                    } 
                }
            }
            dp[i] = temp;
        }
        return dp[N];
    }
};

// solution 2:
class Solution 
{
public:
    bool divisorGame(int N)
    {
        return (!(N&1));//Alice will win iff n is even number
    }
};
