class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        unordered_map <char,int> weight;

        for(int i=0;i<weights.size();i++){
            char ch = 'a' + i;
            weight[ch] = weights[i];
        }

        unordered_map <int,char> map;

        for(int i=0;i<26;i++){
            char ch = 'z' - i;
            map[i] = ch;
        }

        string ans = "";

        for(int i=0;i<words.size();i++){
            int sum = 0;
            for(int j=0;j<words[i].length();j++){
                sum+=weight[words[i][j]];
            }
            ans.push_back(map[sum%26]);
        }
        return ans;
    }
};
