class Solution {
public:
    int solve(vector<int>& nums, int i, int target,
              vector<vector<int>>& dp) {

        if (target == 0) return true;
        if (i == nums.size() || target < 0) return false;

        if (dp[i][target] != -1)
            return dp[i][target];

        return dp[i][target] =
            solve(nums, i + 1, target - nums[i], dp) ||
            solve(nums, i + 1, target, dp);
    }

    bool canPartition(vector<int>& nums) {

        int sum = 0;
        for (int x : nums)
            sum += x;

        if (sum & 1) return false;

        int target = sum / 2;

        vector<vector<int>> dp(nums.size(),
                               vector<int>(target + 1, -1));

        return solve(nums, 0, target, dp);
    }
};
