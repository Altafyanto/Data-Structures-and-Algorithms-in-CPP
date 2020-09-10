// https://leetcode.com/problems/range-sum-query-immutable/

// Time Complexity - O(1) (As NumArray will be called once && Time complexity of sumRange is 0(1))
// Space Complexity - 0(N) (for Caching)

class NumArray
{
public:
    vector<int> sum;
    NumArray(vector<int> &nums)
    {
        int n = nums.size();
        if (n > 0)
        {
            sum.push_back(nums[0]);
            for (int i = 1; i < n; i++)
                sum.push_back(sum[i - 1] + nums[i]);
        }
    }

    int sumRange(int i, int j)
    {
        return i > 0 ? sum[j] - sum[i - 1] : sum[j];
    }
};
