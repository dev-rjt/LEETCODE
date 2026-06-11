class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int open = 0;

        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                open++;
                if(open!=1){
                    ans.push_back(s[i]);
                }

            }
            else{
                open--;
                if(open!=0){
                    ans.push_back(s[i]);
                }
            }
        }
        return ans;   
    }
};
