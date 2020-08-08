/*
  Question:- (https://leetcode.com/explore/featured/card/recursion-i/251/scenario-i-recurrence-relation/3234/)
  
  Two Property of Binomial Coefficient
   1. n       n-1         n-1
       C   =     C     +     C
        k         k-1         k

   2. n       n
       C   =   C
        k       n-k
*/

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        //Base Case
        if(rowIndex == 0)
            return {1};

        auto v = getRow(rowIndex-1);

        for(int i=1,n=v.size(); i<n; i++)
            v[i] = (i <= n/2) ? v[i] + v[n-i] : v[n-i];

        //Last element of row will be 1
        v.push_back(1);
        return v;
    }
};
