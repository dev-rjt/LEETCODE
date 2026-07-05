class Solution {
public:
    int solve(string &s,int low,int high,vector<vector<int>> &dp){
        if(low>=high) return 0;

        if(dp[low][high]!=-1) return dp[low][high];

        int ans = 0;

        if(s[low]==s[high]) ans = solve(s,low+1,high-1,dp);
        else ans = 1+min(solve(s,low+1,high,dp),solve(s,low,high-1,dp));

        return dp[low][high] = ans;
    }
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> dp(n,vector<int>(n,-1));

        return solve(s,0,n-1,dp);
    }
};
