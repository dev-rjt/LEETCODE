class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        const int MOD = 1e9 + 7;

        vector<vector<int>> score(n, vector<int>(n, -1));
        vector<vector<int>> ways(n, vector<int>(n, 0));

        score[n - 1][n - 1] = 0;
        ways[n - 1][n - 1] = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                if (i == n - 1 && j == n - 1)
                    continue;

                if (board[i][j] == 'X')
                    continue;

                int best = -1;

                if (i + 1 < n)
                    best = max(best, score[i + 1][j]);

                if (j + 1 < n)
                    best = max(best, score[i][j + 1]);

                if (i + 1 < n && j + 1 < n)
                    best = max(best, score[i + 1][j + 1]);

                if (best == -1)
                    continue;

                long long cnt = 0;

                if (i + 1 < n && score[i + 1][j] == best)
                    cnt += ways[i + 1][j];

                if (j + 1 < n && score[i][j + 1] == best)
                    cnt += ways[i][j + 1];

                if (i + 1 < n && j + 1 < n &&
                    score[i + 1][j + 1] == best)
                    cnt += ways[i + 1][j + 1];

                cnt %= MOD;

                int val = (board[i][j] == 'E') ? 0 : board[i][j] - '0';

                score[i][j] = best + val;
                ways[i][j] = cnt;
            }
        }

        if (score[0][0] == -1)
            return {0, 0};

        return {score[0][0], ways[0][0]};
    }
};
