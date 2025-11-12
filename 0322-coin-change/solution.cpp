class Solution {
public:
    int solve2(vector<int> coins,int amount,vector<int> &dp) {
        if(amount<0) return INT_MAX;
        if(amount==0) return 0;

        int mini = INT_MAX;

        if(dp[amount]!=-1) return dp[amount];

        for(int i=0;i<coins.size();i++) {
            int ans = solve2(coins,amount-coins[i],dp);
            if(ans!=INT_MAX) mini = min(mini,ans+1);
        }
        dp[amount] = mini;
        return dp[amount];
    }

    
    int coinChange(vector<int>& coins, int amount) {

        vector <int> dp(amount+1,-1);
        solve2(coins,amount,dp);
        int x = solve2(coins,amount,dp);
        if(x==INT_MAX) return -1;
        else return x;
    }
};
