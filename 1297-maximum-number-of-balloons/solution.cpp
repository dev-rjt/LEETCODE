class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map <char,int> freq;
        
        for(int i=0;i<text.length();i++) freq[text[i]]++;

        int ans = 10000;

        ans = min(ans,min(freq['b'],min(freq['a'],min(freq['l']/2,min(freq['o']/2,freq['n'])))));

        return ans;
    }
};
