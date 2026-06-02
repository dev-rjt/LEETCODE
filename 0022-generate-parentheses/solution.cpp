class Solution {
public:
    void solve(int n,int open,int close,string possible,vector<string> &ans){
        if(open+close==2*n-1){
            possible.push_back(')');
            ans.push_back(possible);
            return;
        }

        if(open<n){
            possible.push_back('(');
            solve(n,open+1,close,possible,ans);
            possible.pop_back();
        }

        if(close<open){
            possible.push_back(')');
            solve(n,open,close+1,possible,ans);
            possible.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(n,0,0,"",ans);
        return ans;
    }
};
