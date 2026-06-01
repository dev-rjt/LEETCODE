class Solution {
  public:
    bool solve(string &s,vector<string> &dictionary,int i,vector<int> &dp){
        if(i==s.length()) return true;
        
        if(dp[i]!=-1) return dp[i];
        
        for(int j = 0;j<dictionary.size();j++){
            int temp = i;
            string word = dictionary[j];
            
            if(dictionary[j].length()>s.length()-i){
                continue;
            }
            
            bool possible = true;
            
            for(auto it: word){
                if(it==s[temp]) temp++;
                else {
                    possible=false;
                    break;
                }
            }
            
            if(possible){
                bool res = solve(s,dictionary,temp,dp);
                if(res){
                    dp[i] = true;
                    return true;
                }
            }
        }
        dp[i] = false;
        return false;
        
    }
    bool wordBreak(string s, vector<string> &dictionary) {
        // code here
        vector<int> dp(s.length(),-1);
        return solve(s,dictionary,0,dp);
    }
};
