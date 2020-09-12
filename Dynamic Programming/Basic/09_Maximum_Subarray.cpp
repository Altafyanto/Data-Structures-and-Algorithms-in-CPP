// https://leetcode.com/problems/maximum-subarray/

//Time Complexity - O(N), Space Complexity -O(1)

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        if(n == 1)
            return nums[0];

        // We have to take atleast one element
        int result = nums[0], previous = nums[0];
        for (int i = 1; i < n; i++)
        {
            // Adding previous result if it is positive
            previous = nums[i] + (previous > 0 ? previous : 0);
            result = max(result, previous);
        }

        return result;
    }
};
