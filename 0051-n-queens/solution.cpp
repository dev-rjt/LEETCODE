class Solution {
public:

    void solve(int n,int i,vector<pair<int,int>> &res,vector<vector<pair<int,   int>>> &ans){

        // base case
        if(i==n){
            ans.push_back(res);
            return;
        }

        for(int j=0;j<n;j++){
            bool possible = true;

            for(auto it: res){
                int a  = it.first;
                int b = it.second;

                if(i==a || j==b || i-j == a-b || i+j==a+b ){
                    possible = false;
                    break;
                }
            }

            if(possible){
                res.push_back({i,j});
                solve(n,i+1,res,ans);
                res.pop_back();
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<pair<int,int>> res;
        vector<vector<pair<int,int>>> ans;

        solve(n,0,res,ans);

        vector<vector<string>> ret;

        for(auto it:ans){
            vector<string> temp(n,string(n,'.'));

            for(auto i:it){
                temp[i.first][i.second] = 'Q';
            }

            ret.push_back(temp);
        }

        return ret;
    }
};
