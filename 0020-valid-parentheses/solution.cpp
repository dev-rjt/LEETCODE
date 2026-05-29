class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        int poss = 1;
        
        for(int i=0;i<s.length();i++){
            if(s[i]=='{' || s[i]=='[' || s[i]=='('){
                st.push(s[i]);
                continue;
            }
            
            if(!st.empty() && s[i]==')' && st.top()=='(') st.pop();
            else if(!st.empty() && s[i]=='}' && st.top()=='{') st.pop();
            else if(!st.empty() && s[i]==']' && st.top()=='[') st.pop();
            else{
                poss = 0;
                break;
            }
            
        }
        
        if(st.empty()&&poss) return true;
        else return false;
    }
};
