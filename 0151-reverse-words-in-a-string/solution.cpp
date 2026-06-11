class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int i = n-1;
        int j = n-1;

        string ans = "";

        while(i>=0){
            if(s[i]==' '){
                j=i+1;
                bool word = false;
                while(j<n && s[j]!=' '){
                    ans.push_back(s[j]);
                    j++;
                    word = true;
                }
                if(word) ans.push_back(' ');
            }
            i--;
        }

        bool word = false;
        j=0;
        while(j<n && s[j]!=' '){
            ans.push_back(s[j]);
            j++;
            word = true;
        }

        if(!word){
            ans.pop_back();
        }
        return ans;
    }
};
