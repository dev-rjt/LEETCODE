class Solution {
public:
    bool check(string &s1,string &s2){
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i]) return false;
        }
        return true;
    }

    int change(string &s1,string &s2){
        int ans = 0;
        int n = s1.length();
        
        for(int i=0;i<n;i++){
            if(s1[i]==s2[i]) continue;

            if(s1[i]=='0'){
                ans+=1;
                s1[i] = '1';
            }
            else if(s1[i]=='1'){
                if(i+1<n){
                    if(s1[i+1]=='1'){
                        ans+=1;
                        s1[i+1] = '0';
                        s1[i] = '0';
                    }
                    else{
                        ans+=2;
                        s1[i] = '0';
                    }
                }
                else if(i-1>=0){
                    ans+=2;
                    s1[i] = '0';
                }
                
            }
        }
        return ans;
    }
    int minOperations(string s1, string s2) {

        int ans = change(s1,s2);

        if(check(s1,s2)) return ans;
        return -1;
        
    }
};
