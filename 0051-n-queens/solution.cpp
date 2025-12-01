class Solution {
public:

    void solve(int n,int r,vector<int>&col,vector<int> &d1,vector<int>&d2, vector<string> &board,vector<vector<string>> &ans){
        if(r==n){
            ans.push_back(board);
            return;
        }

        for(int c=0;c<n;c++) {
            if(col[c]||d1[r+c]||d2[n-c+r-1]) continue;

            col[c]=1;d1[r+c]=1;d2[n-c+r-1]=1;
            board[r][c] = 'Q';

            solve(n,r+1,col,d1,d2,board,ans);

            board[r][c] = '.';

            col[c]=0;d1[r+c]=0;d2[n-c+r-1]=0;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        vector<vector<string>> ans;

        vector<int> col(n,0);
        vector<int> d1(2*n,0);
        vector<int> d2(2*n,0);

       solve(n,0,col,d1,d2,board,ans);

       return ans;
    }
};
