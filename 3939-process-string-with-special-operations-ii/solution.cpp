class Solution {
public:
    char processStr(string s, long long k) {
        long long len = 0;
        int n = s.length();

        for(int i=0;i<n;i++){
            if(s[i]=='*'){
                if(len) len-=1;
            }
            else if(s[i]=='#') len*=2;
            else if(s[i]=='%') continue;
            else len+=1;
        }

        if(len<=k) return '.';

        for(int i=n-1;i>=0;i--){
            if(s[i]=='*'){
                len+=1;
                continue;
            }
            else if(s[i]=='#'){
                if(k>=len/2){
                    k-=len/2;
                }
                len = len/2;
            }
            else if(s[i]=='%'){
                k = len-k-1;
            }
            else{
                if(k==len-1) return s[i];
                else len--;
            }
        }
        return '.';
    }
};
