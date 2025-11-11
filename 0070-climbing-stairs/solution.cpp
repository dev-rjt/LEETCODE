class Solution {
public:

    int climb(int dp[],int n){
        if(n==0) return 1;
        if(n<0) return 0;

        if(dp[n]!=-1) return dp[n];

        dp[n] = climb(dp,n-1) + climb(dp,n-2);
        return dp[n];
    }

    int climbStairs(int n) {
       int dp[n+1];
       for(int i=0;i<n+1;i++) dp[i] = -1;


       return climb(dp,n);
    }
};
