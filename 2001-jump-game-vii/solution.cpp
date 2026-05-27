class Solution {
public:

    bool canReach(string s, int minJump, int maxJump) {

       int n = s.length();

        vector<int> dp(n,0);

        dp[0] = 1;

        int reachable = 0;

        for(int i=1;i<n;i++){

            // add new index entering window
            if(i - minJump >= 0){
                reachable += dp[i - minJump];
            }

            // remove old index leaving window
            if(i - maxJump - 1 >= 0){
                reachable -= dp[i - maxJump - 1];
            }

            // current index reachable?
            if(reachable > 0 && s[i]=='0'){
                dp[i] = 1;
            }
        }

        return dp[n-1];
    }
};
