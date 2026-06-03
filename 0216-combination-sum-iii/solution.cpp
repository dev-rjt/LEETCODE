class Solution {
public:
    void solve(int k,int n,int num,vector<int> &res,vector<vector<int>> &ans){
        if(k==0){
            if(n==0) ans.push_back(res);
            return;
        }
        if(n<0) return;
        if(num>9) return;

        res.push_back(num);
        solve(k-1,n-num,num+1,res,ans);
        res.pop_back();

        solve(k,n,num+1,res,ans);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> res;
        vector<vector<int>> ans;
        solve(k,n,1,res,ans);
        return ans;
    }
};
