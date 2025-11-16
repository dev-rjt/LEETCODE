class Solution {
public:
    int solve(vector<int> &v,int i,int j,vector<vector<int>> &dp) {
        if(j-i<2) return 0;

        int mini = INT_MAX;

        if(dp[i][j]!=-1) return dp[i][j];

        for(int k=i+1;k<j;k++) {
            int ans = v[i]*v[j]*v[k] + solve(v,i,k,dp) + solve(v,k,j,dp);
            mini = min(mini,ans);
        }
        dp[i][j] = mini;
        return mini;
    }
    
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(51,vector<int>(51,-1));
        return solve(values,0,n-1,dp);
    }
};
