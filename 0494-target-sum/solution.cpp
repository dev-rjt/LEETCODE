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
        int TotalSum = 0;

        for(auto i:nums) TotalSum+=i;

        vector<vector<int>> dp(n,vector<int>(2*TotalSum+1,0));
        dp[0][TotalSum+nums[0]] = 1;
        dp[0][TotalSum-nums[0]] += 1;

        for(int i=1;i<n;i++){
            for(int sum=-TotalSum;sum<=TotalSum;sum++){
                if(dp[i-1][sum+TotalSum]>0){
                    dp[i][sum+TotalSum+nums[i]] += dp[i-1][sum+TotalSum];
                    dp[i][sum+TotalSum-nums[i]] += dp[i-1][sum+TotalSum];
                }
            }
        }

        return abs(target)>TotalSum ? 0: dp[n-1][target+TotalSum];
    }
};
