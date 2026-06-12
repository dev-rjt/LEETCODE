class Solution {
public:
    int maxDepth(string s) {
        int freq = 0;   
        int ans = 0;

        for(int i=0;i<s.length();i++){
            if(s[i]=='(') freq++;
            if(s[i]==')') freq--;
            ans = max(ans,freq);
        }
        return ans;
    }
};
