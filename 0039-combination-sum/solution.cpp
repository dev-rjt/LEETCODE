class Solution {
public:
    void solve(vector<int>& arr, int target, int idx,
               vector<int>& cur,
               vector<vector<int>>& ans) {

        if(target == 0) {
            ans.push_back(cur);
            return;
        }

        for(int i = idx; i < arr.size(); i++) {
            if(arr[i] > target) break;

            cur.push_back(arr[i]);
            solve(arr, target - arr[i], i, cur, ans);
            cur.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates,
                                       int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> cur;

        solve(candidates, target, 0, cur, ans);
        return ans;
    }
};
