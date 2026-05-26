class Solution {
public:
    int solve(vector<int> &nums,int i,vector<int> &dp,int n){
        if(i>n-1) return 0;
        if(i==n-1) return nums[n-1];
        
        if(dp[i]!=-1) return dp[i];
        
        dp[i] = max(nums[i] + solve(nums,i+2,dp,n),solve(nums,i+1,dp,n));
        return dp[i];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return solve(nums,0,dp,n);
    }
};
