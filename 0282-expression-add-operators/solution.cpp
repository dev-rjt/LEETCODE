class Solution {
public:
    void solve(const string& num, int target, int idx, long long val,
               long long prev, string expr, vector<string>& ans) {
        if (idx == num.size()) {
            if (val == target) ans.push_back(expr);
            return;
        }

        for (int i = idx; i < num.size(); i++) {
            if (i > idx && num[idx] == '0') break;

            string curStr = num.substr(idx, i - idx + 1);
            long long cur = stoll(curStr);

            if (idx == 0)
                solve(num, target, i + 1, cur, cur, curStr, ans);
            else {
                solve(num, target, i + 1, val + cur, cur,
                      expr + "+" + curStr, ans);

                solve(num, target, i + 1, val - cur, -cur,
                      expr + "-" + curStr, ans);

                solve(num, target, i + 1,
                      val - prev + prev * cur,
                      prev * cur,
                      expr + "*" + curStr, ans);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        solve(num, target, 0, 0, 0, "", ans);
        return ans;
    }
};
