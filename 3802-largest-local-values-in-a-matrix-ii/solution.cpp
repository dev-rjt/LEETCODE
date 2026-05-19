class Solution {
public:

    int getSum(vector<vector<int>>& pref,
               int r1, int c1,
               int r2, int c2) {

        if(r1 > r2 || c1 > c2)
            return 0;

        int ans = pref[r2][c2];

        if(r1 > 0) ans -= pref[r1 - 1][c2];
        if(c1 > 0) ans -= pref[r2][c1 - 1];
        if(r1 > 0 && c1 > 0)
            ans += pref[r1 - 1][c1 - 1];

        return ans;
    }

    int countLocalMaximums(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        int ans = 0;

        // values are small (0..200)
        for(int val = 1; val <= 200; val++) {

            // build prefix matrix for cells > val
            vector<vector<int>> pref(n, vector<int>(m,0));

            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {

                    pref[i][j] = (matrix[i][j] > val);

                    if(i > 0) pref[i][j] += pref[i-1][j];
                    if(j > 0) pref[i][j] += pref[i][j-1];
                    if(i > 0 && j > 0)
                        pref[i][j] -= pref[i-1][j-1];
                }
            }

            // check cells having value = val
            for(int r = 0; r < n; r++) {
                for(int c = 0; c < m; c++) {

                    if(matrix[r][c] != val)
                        continue;

                    int x = val;

                    int r1 = max(0, r - x);
                    int c1 = max(0, c - x);

                    int r2 = min(n - 1, r + x);
                    int c2 = min(m - 1, c + x);

                    int cnt = getSum(pref, r1, c1, r2, c2);

                    // remove excluded corners if counted
                    vector<pair<int,int>> corners = {
                        {r-x,c-x},
                        {r-x,c+x},
                        {r+x,c-x},
                        {r+x,c+x}
                    };

                    for(auto &[i,j] : corners) {

                        if(i < 0 || i >= n || j < 0 || j >= m)
                            continue;

                        if(matrix[i][j] > x)
                            cnt--;
                    }

                    if(cnt == 0)
                        ans++;
                }
            }
        }

        return ans;
    }
};
