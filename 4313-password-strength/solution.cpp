class Solution {
public:
    int passwordStrength(string password) {

        unordered_set<char> seen;

        int ans = 0;

        for(char ch : password){

            if(seen.count(ch)) continue;

            seen.insert(ch);

            if(islower(ch)){
                ans += 1;
            }
            else if(isupper(ch)){
                ans += 2;
            }
            else if(isdigit(ch)){
                ans += 3;
            }
            else if(ch=='!' || ch=='@' || ch=='#' || ch=='$'){
                ans += 5;
            }
        }

        return ans;
    }
};
