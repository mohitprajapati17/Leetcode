class Solution {
public:
    int n;

    int rec(vector<int>& nums, int index, int prev, vector<vector<int>>& dp) {

        if(index == n)
            return 0;

        if(dp[index][prev + 1] != -1)
            return dp[index][prev + 1];

        int take = 0;

        if(prev == -1 || nums[index] > nums[prev])
            take = 1 + rec(nums, index + 1, index, dp);

        int notTake = rec(nums, index + 1, prev, dp);

        return dp[index][prev + 1] = max(take, notTake);
    }

    int lengthOfLIS(vector<int>& nums) {

        n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return rec(nums, 0, -1, dp);
    }
};