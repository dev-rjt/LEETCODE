class Solution {
public:
    int solve(string &s,int low,int high,vector<vector<int>> &dp){
        if(low>high) return 0;

        if(low==high) return 1;

        if(dp[low][high]!=-1) return dp[low][high];

        int ans = 0;

        if(s[low]==s[high]) ans = 2 + solve(s,low+1,high-1,dp);
        else ans = max(solve(s,low+1,high,dp),solve(s,low,high-1,dp));

        return dp[low][high] = ans;
    }


    int longestPalindromeSubseq(string s) {
        int n = s.size();

        vector<int> prev(n, 0), curr(n, 0);

        for (int i = n - 1; i >= 0; i--) {
            curr[i] = 1;             

            for (int j = i + 1; j < n; j++) {
                int temp = prev[j];   

                if (s[i] == s[j])
                    curr[j] = 2 + prev[j-1];
                else
                    curr[j] = max(prev[j], curr[j - 1]);

            }

            prev = curr;
        }

        return prev[n - 1];
    }
};
