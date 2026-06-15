class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        for(char ch : num) {
            while(!st.empty() && st.top() > ch && k) {
                st.pop();
                k--;
            }
            st.push(ch);
        }

        while(k--) st.pop();

        string ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        int i = 0;
        while(i < ans.size() && ans[i] == '0') i++;

        ans = ans.substr(i);

        return ans.empty() ? "0" : ans;
    }
};
