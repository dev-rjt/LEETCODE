class Solution {
public:
    string longestPalindrome(string s) {
        // odd palindromes
        int ans = 0;
        int ans_left=0;
        int ans_right = -1;

        int l=0;
        int r = -1;
        int n = s.length();

        vector<int> dp1(n,-1);

        for(int i=0;i<n;i++){
            int k = (i>r) ? 1:min(dp1[l+r-i],r-i+1);
            while(i-k>=0 && i+k<n && s[i-k]==s[i+k]) k++;

            dp1[i] = k;

            if(ans<2*k-1){
                ans = 2*k-1;
                ans_left = i-k+1;
                ans_right = i+k-1;
            }

            if(i+k-1>r){
                l = i-k+1;
                r = i+k-1;
            }
        }

        l=0;
        r=-1;

        vector<int> dp2(n,-1);

         for(int i=0;i<n;i++){
            int k = (i>r) ? 0:min(dp2[l+r-i+1],r-i+1);
            while(i-k-1>=0 && i+k<n && s[i-k-1]==s[i+k]) k++;

            dp2[i] = k;

            if(ans<2*k){
                ans = 2*k;
                ans_left = i-k;
                ans_right = i+k-1;
            }

            if(i+k-1>r){
                l = i-k;
                r = i+k-1;
            }
        }

        string res = "";

        for(int i=ans_left;i<=ans_right;i++) res.push_back(s[i]);

        return res;
    }
};
