class Solution {
public:
    bool isValid(string s) {
        int size = s.length();

        stack <char> s1;


        for(int i=0;i<size;i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[') s1.push(s[i]);

            if(s[i]==')' || s[i]=='}' || s[i]==']') {
                if(s1.size()<1) return false;

                else if(s[i]==')' && s1.top() == '('|| s[i]=='}' && s1.top() == '{' || s[i]==']' && s1.top() == '[') {
                    s1.pop();
                    continue;
                }

                else return false;
            }

        }

        if(s1.size()>0) return false;

        else return true;
    }
};
