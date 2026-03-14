class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map <char,int> map1;
        unordered_map <char,int> map2;

        if(s.length()!=t.length()) return false;

        for(int i=0;i<s.length();i++) map1[s[i]]++;
        for(int i=0;i<t.length();i++) map2[t[i]]++;

        for(auto i:map1){
            if(map2[i.first]!=i.second) return false;
        }
        return true;

    }
};
