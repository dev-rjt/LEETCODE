class Solution {
public:
    string minWindow(string s, string t) {

        if(t.length() > s.length()) return "";

        vector<int> req_freq(128, 0);
        for(int i = 0; i < t.length(); i++) req_freq[t[i]]++;

        int left = 0;
        int ans = INT_MAX;
        int ans_left = -1;
        int ans_right = -1;

        vector<int> freq(128, 0);

        for(int right = 0; right < s.length(); right++) {

            freq[s[right]]++;

            bool contains = true;

            for(int j = 0; j < 128; j++) {
                if(freq[j] < req_freq[j]) {
                    contains = false;
                    break;
                }
            }

            if(contains) {

                while(left <= right && freq[s[left]] > req_freq[s[left]]) {
                    freq[s[left]]--;
                    left++;
                }

                if(ans > right - left + 1) {
                    ans = right - left + 1;
                    ans_left = left;
                    ans_right = right;
                }
            }
        }

        if(ans_left == -1) return "";

        return s.substr(ans_left, ans_right - ans_left + 1);
    }
};
