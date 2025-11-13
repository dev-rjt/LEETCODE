class Solution {
public:

    int solve(int i,vector <int> &days,vector <int> &costs,vector <int> &dp) {
        if(i>days.size()-1) return 0;

        if(dp[i]!=-1) return dp[i];

        int one  = solve(i+1,days,costs,dp)+costs[0];

        int j = i;
        while(j<days.size() && days[j]<days[i]+7) j++;
        int seven = solve(j,days,costs,dp) + costs[1];
        
        int k = i;
        while(k<days.size() && days[k]<days[i]+30) k++;
        int thirty = solve(k,days,costs,dp) + costs[2];

        int ans = min(one,min(seven,thirty));
        dp[i] = ans;
        return dp[i];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector <int> dp(days.size()+1,-1);
        return solve(0,days,costs,dp);
    }
};
