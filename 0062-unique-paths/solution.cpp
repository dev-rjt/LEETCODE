class Solution {
public:

    int solve(int m,int n,vector<vector<int>> &dp,int i,int j) {
        if(i>=m || j>=n) return 0;
        if(i==m-1 && j==n-1) return 1;

        if(dp[i][j]!=-1) return dp[i][j];

        int ans = solve(m,n,dp,i+1,j) + solve(m,n,dp,i,j+1);

        dp[i][j] = ans;
        return ans;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));

        return solve(m,n,dp,0,0);
    }
};
