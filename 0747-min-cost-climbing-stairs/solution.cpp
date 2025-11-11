class Solution {
public:
    int solve1(vector<int> cost,int n,vector <int> &dp) {
        // base case step 1
        if(n==0) return cost[0];
        if(n==1) return cost[1];

        //step 3
        if(dp[n]!=-1) return dp[n];

        // step 2
        dp[n]= cost[n] + min(solve1(cost,n-1,dp),solve1(cost,n-2,dp));
        return dp[n];
    }

    int solve2(vector<int> cost,int n){
        vector<int> dp(n+1);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i=2;i<n;i++) {
            dp[i] = cost[i] +min(dp[i-1],dp[i-2]);
        }
        return min(dp[n-1],dp[n-2]);
    }

    int solve3(vector<int> cost,int n){
        int prev1 = cost[0];
        int prev2 = cost[1];
        int curr = 0;

        for(int i=2;i<n;i++) {
        curr = cost[i] +min(prev1,prev2);
        prev1 = prev2;
        prev2 = curr;
        }

        return min(prev1,prev2);

    }

    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // vector<int> dp(n+1,-1);
        //int ans = min(solve1(cost,n-1,dp),solve1(cost,n-2,dp));
        // int ans = solve2(cost,n);
        int ans = solve3(cost,n);
        return ans;
    }
};
