class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> freq(3,0);  
        int left = 0;
        int x = 0;
        int ans = 0;

        for(int right=0;right<s.size();right++){
            char ch = s[right];
            freq[ch-'a']++;

            if(freq[0]>=1 && freq[1]>=1 && freq[2]>=1){
                while(freq[s[left]-'a']>1){
                    freq[s[left]-'a']--;
                    left++;
                    x++;
                }
                ans+=1+x;
            }
           
        }
        return ans;
    }
};
