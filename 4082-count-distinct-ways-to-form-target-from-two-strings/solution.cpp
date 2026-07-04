class Solution {
public:
    const int MOD = 1e9 + 7;

    int solve(string& word1, string& word2, string& target,
              vector<vector<int>>& pos1, vector<vector<int>>& pos2,
              int last1, int last2, int idx, int mask,
              vector<vector<vector<vector<int>>>>& dp) {

        if (idx == target.size())
            return mask == 3;

        if (dp[last1 + 1][last2 + 1][idx][mask] != -1)
            return dp[last1 + 1][last2 + 1][idx][mask];

        long long ans = 0;
        int ch = target[idx] - 'a';

        for (int index : pos1[ch]) {
            if (index > last1) {
                ans = (ans + solve(word1,word2,target, pos1,                            pos2, index,last2, idx+1, mask|1,dp))%MOD;
            }
        }

        for (int index : pos2[ch]) {
            if (index > last2) {
                    ans = (ans + solve(word1,word2,target,pos1,                            pos2,last1,index,idx+1, mask|2,dp))%MOD;
            }
        }

        return dp[last1 + 1][last2 + 1][idx][mask] = ans;
    }

    int interleaveCharacters(string word1, string word2, string target) {

        int n = word1.size();
        int m = word2.size();
        int k = target.size();

        vector<vector<vector<vector<int>>>> dp(n+1,
        vector<vector<vector<int>>>(m+1,vector<vector<int>>(k+1,
        vector<int>(4,-1))));

        vector<vector<int>> pos1(26), pos2(26);

        for (int i = 0; i < n; i++)
            pos1[word1[i] - 'a'].push_back(i);

        for (int i = 0; i < m; i++)
            pos2[word2[i] - 'a'].push_back(i);

        return solve(word1,word2,target,pos1,pos2,-1,-1,0,0,dp);
    }
};
