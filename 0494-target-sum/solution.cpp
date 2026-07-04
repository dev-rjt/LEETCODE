class Solution {
public:
    int count(vector<int>& nums, int target,int n,vector<vector<int>> &dp,int i,int sum){

        if(target>sum || target < -sum) return 0;
        
        if(i>=n) return target==0;

        if(dp[i][target+sum]!=-1) return dp[i][target+sum];

        return dp[i][target+sum] = count(nums,target-nums[i],n,dp,i+1,sum) + count(nums,target+nums[i],n,dp,i+1,sum);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;

        for(auto i:nums) sum+=i;

        vector<vector<int>> dp(n,vector<int>(2*sum+1,-1));

        return count(nums,target,n,dp,0,sum);
    }
};
