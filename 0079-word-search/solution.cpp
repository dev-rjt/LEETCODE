class Solution {
public:
    bool solve(vector<vector<char>>& board, string &word,
               vector<vector<int>>& visited,
               int i, int j, int n, int m, int index) {

        if(i < 0 || i >= n || j < 0 || j >= m)
            return false;

        if(visited[i][j])
            return false;

        if(board[i][j] != word[index])
            return false;

        if(index == word.length() - 1)
            return true;

        visited[i][j] = 1;

        int dx[] = {-1, 0, 0, 1};
        int dy[] = {0, 1, -1, 0};

        for(int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];

            if(solve(board, word, visited, x, y, n, m, index + 1))
                return true;
        }

        visited[i][j] = 0; // backtrack
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                vector<vector<int>> visited(n, vector<int>(m, 0));

                if(solve(board, word, visited, i, j, n, m, 0))
                    return true;
            }
        }

        return false;
    }
};
