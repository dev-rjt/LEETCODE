class Solution {
public:

    int solve(int n,vector<vector<int>> &triangle,int i,int j,vector<vector<int>>& dp) {
        if(i==n-1) return triangle[i][j];
        
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = triangle[i][j] + min(solve(n,triangle,i+1,j,dp),solve(n,triangle,i+1,j+1,dp));
        dp[i][j] = ans;
        return ans;
    }

    int tab(int n,vector<vector<int>> &triangle,vector<vector<int>>& dp) {
        for(int j=0;j<n;j++) dp[n-1][j] = triangle[n-1][j];

        for(int i=n-2;i>=0;i--) {
            for(int j=0;j<=i;j++) {
                dp[i][j] = triangle[i][j] + min(dp[i+1][j],dp[i+1][j+1]);
            }
        }

        return dp[0][0];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        // return solve(n,triangle,0,0,dp);

        return tab(n,triangle,dp);
    }
};
