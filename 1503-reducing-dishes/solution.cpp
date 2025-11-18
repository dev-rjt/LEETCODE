class Solution {
public:

    int solve(int n,vector<int> &satisfaction,int time,int pos,vector<vector<int>> &dp) {
        //base case
        if(pos==n-1) return time*satisfaction[pos];

        if(dp[time][pos]!=-1) return dp[time][pos];

        //solve
        int include = time*satisfaction[pos] + solve(n,satisfaction,time+1,pos+1,dp);
        int exclude = solve(n,satisfaction,time,pos+1,dp);

        int ans = max(include,exclude);
        dp[time][pos] = ans;
        return ans;
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int n = satisfaction.size();

        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

        int x = solve(n,satisfaction,1,0,dp);

        if(x<0) return 0;
        else return x;
    }
};
