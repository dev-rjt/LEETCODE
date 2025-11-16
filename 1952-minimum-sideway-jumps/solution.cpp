class Solution {
public:

    int solve(int pos,vector<int> &obstacles,int lane,vector<vector<int>> &dp) {
        if(pos==obstacles.size()-1) return 0;

        if(dp[lane][pos]!=-1) return dp[lane][pos];

        if(obstacles[pos+1]!=lane) return solve(pos+1,obstacles,lane,dp);

        int ans = 0;

        if(lane==1) {
            if(obstacles[pos]==2) ans = 1 + solve(pos,obstacles,3,dp);
            else if(obstacles[pos]==3) ans = 1 + solve(pos,obstacles,2,dp);
            else ans = 1+ min(solve(pos,obstacles,2,dp),solve(pos,obstacles,3,dp));
        }

        if(lane==2) {
            if(obstacles[pos]==1) ans = 1 + solve(pos,obstacles,3,dp);
            else if(obstacles[pos]==3) ans = 1 + solve(pos,obstacles,1,dp);
            else ans = 1+ min(solve(pos,obstacles,1,dp),solve(pos,obstacles,3,dp));
        }

        if(lane==3) {
            if(obstacles[pos]==2) ans = 1 + solve(pos,obstacles,1,dp);
            else if(obstacles[pos]==1) ans = 1 + solve(pos,obstacles,2,dp);
            else ans = 1+ min(solve(pos,obstacles,2,dp),solve(pos,obstacles,1,dp));
        }

        dp[lane][pos] = ans;
        return ans;

    }

    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<vector<int>> dp(4,vector<int>(1000000,-1));
        int x = solve(0,obstacles,2,dp);

        return x;

    }
};
