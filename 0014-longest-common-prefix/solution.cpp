class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans= "";

        for(int i=0;i<strs[0].size();i++){
            char ch = strs[0][i];
            int common = 0;

            for(int j=0;j<strs.size();j++){
                if(strs[j][i]==ch) common++;
                else break;
            }

            if(common == strs.size()) ans.push_back(ch);
            else break;
        }

        return ans;
    }
};
