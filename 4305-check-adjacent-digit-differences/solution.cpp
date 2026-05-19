class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        int i = 0;
        while(i<s.length()-1){
            int a = s[i] - '0';
            int b = s[i+1] - '0';
            if(abs(a-b)>2) return false;
            i++;
        }
        return true;
    }
};
