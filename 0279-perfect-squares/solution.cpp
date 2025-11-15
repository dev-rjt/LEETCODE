class Solution {
public:

    int solve(int n,vector<int> &dp) {
        if(n<0) return INT_MAX;
        if(n==0) return 0;

        if(dp[n]!=-1) return dp[n];

        int mini = INT_MAX;

        for(int j=1;j*j<=n;j++){
            int ans = 1 + solve(n-j*j,dp);
            mini = min(mini,ans);
        }

        dp[n] = mini;
        return mini;
    }

    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        int x = solve(n,dp);

        if(x==INT_MAX) return -1;
        else return x;
    }
};
