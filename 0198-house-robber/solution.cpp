class Solution {
public:
int solve(vector<int> &nums,int pos,vector<int> &dp) {
        // base case
        if(pos>=nums.size()) return 0;
        if(nums.size()-pos==1) return nums[pos];
        
        if(dp[pos]!=-1) return dp[pos];
        
        int include = solve(nums,pos+2,dp) + nums[pos];
        int exclude = solve(nums,pos+1,dp);
        dp[pos] =  max(include,exclude);
        
        return dp[pos];
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        
        return solve(nums,0,dp);
    }
};
