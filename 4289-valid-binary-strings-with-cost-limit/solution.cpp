class Solution {
public:
    void solve(int n,int cost,string poss,bool one,vector<string> &ans,int i){
        if(cost<0) return;
        if(i==n){
            ans.push_back(poss);
            return;
        }

        poss.push_back('0');
        solve(n,cost,poss,true,ans,i+1);
        poss.pop_back();

        if(one){
            poss.push_back('1');
            solve(n,cost-i,poss,false,ans,i+1);
            poss.pop_back();
        }
    }
    vector<string> generateValidStrings(int n, int k) {
        vector<string> ans;
        solve(n,k,"",true,ans,0);
        return ans;
    }
};
