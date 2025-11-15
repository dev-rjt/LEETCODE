class Solution {
public:


    int solve(int n,vector<int> days,vector <int> costs,int pos,vector<int> &dp){
        if(pos>=n) return 0;
        if(pos==n-1) return min(costs[0],min(costs[1],costs[2]));

        if(dp[pos]!=-1) return dp[pos];

        int a = INT_MAX;
        a = solve(n,days,costs,pos+1,dp) + costs[0];

        int b = INT_MAX;
        int j = pos;
        while(j<n && days[j]-days[pos]<7) j++;
        b = solve(n,days,costs,j,dp) + costs[1];

        int c = INT_MAX;
        j = pos;
        while(j<n && days[j]-days[pos]<30) j++;
        c = solve(n,days,costs,j,dp) + costs[2];

        int ans = min(a,min(b,c));
        dp[pos] = ans;
        return ans;

    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector <int> dp(n,-1);
        return solve(n,days,costs,0,dp);
    }
};
