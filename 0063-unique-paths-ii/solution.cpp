class Solution {
public:

    int solve(int m,int n,vector<vector<int>> &obstacleGrid,vector<vector<int>> &dp,int i,int j){
        if(i>=m || j>=n) return 0;
        if(i==m-1 && j==n-1) return 1;
        if(obstacleGrid[i][j]==1) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int ans = solve(m,n,obstacleGrid,dp,i+1,j) + solve(m,n,obstacleGrid,dp,i,j+1);

        dp[i][j] = ans;
        return ans;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1]==1) return 0;

        vector<vector<int>> dp(m,vector<int>(n,-1));

        return solve(m,n,obstacleGrid,dp,0,0);
    }
};
