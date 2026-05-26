class Solution {
public:
    int solve(int n,vector<int> &dp){
        if(n==1) return 1;
        if(n==2) return 2;
        
        if(dp[n]!=0) return dp[n];
        
        dp[n] = solve(n-1,dp) + solve(n-2,dp) ;
        
        return dp[n];
    }
    int climbStairs(int n) {
        // code here
        vector<int> dp(n+1,0);
        int ans = solve(n,dp);
        return ans;
    }
};
