class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map <char,int> freq;

        for(int i=0;i<word.length();i++){
            freq[word[i]]++;
        }

        int ans = 0;

        for(int i=0;i<word.length();i++){
            char ch = word[i];
            char ch1 = tolower(ch);
            char ch2 = toupper(ch);

            if(freq[ch1]>0 && freq[ch2]>0){
                ans++;
                freq[ch1] = 0;
                freq[ch2] = 0;
            }
            
        }

        return ans;
    }
};
