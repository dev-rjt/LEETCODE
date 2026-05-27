class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,int> freq;
        int ans = 0;

        for(int i=0;i<word.length();i++){
            char lower = tolower(word[i]);
            char upper = toupper(word[i]);

            int val = word[i] + 0;

            if(65<=val && val<=90){
                if(freq[lower] && freq[upper]){
                    // freq[lower] = 0;
                }

                else if(freq[lower]){
                    freq[upper]=1;  
                    ans++;
                }

                else{
                    freq[upper] = 1;
                }
            }
            else{
                if(freq[upper] && freq[lower]){
                    ans--;
                    freq[lower] = 0;
                }

                else if(freq[upper]){
                    freq[lower] = 0;
                }

                else{
                    freq[lower] = 1;
                }
            }

            // cout << ans << endl;
        }

        return ans;
    }
};
