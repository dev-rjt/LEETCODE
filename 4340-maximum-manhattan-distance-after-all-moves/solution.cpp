class Solution {
public:
    int maxDistance(string s) {
        int horizontal = 0;
        int vertical = 0;
        int spaces = 0;

        for(int i=0;i<s.length();i++){
            if(s[i]=='U') vertical++;
            else if(s[i]=='D') vertical--;
            else if(s[i]=='L') horizontal--;
            else if(s[i]=='R') horizontal++;
            else spaces++;

        }

       

        return abs(horizontal) + abs(vertical) + spaces;
    }
};
