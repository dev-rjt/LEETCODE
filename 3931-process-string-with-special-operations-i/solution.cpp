class Solution {
public:
    string processStr(string s) {
        string ans = "";

        for(int i=0;i<s.length();i++){
            if(s[i]=='*'){
                if(ans.length()) ans.pop_back();
            }
            else if(s[i]=='#') ans+=ans;
            else if(s[i]=='%') reverse(ans.begin(),ans.end());
            else ans.push_back(s[i]);
        }
        return ans;
    }
};
