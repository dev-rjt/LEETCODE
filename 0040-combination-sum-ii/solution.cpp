class Solution {
public:
    void solve(vector<int>& arr,
               int target,
               int start,
               vector<int>& cur,
               vector<vector<int>>& ans) {

        if(target == 0) {
            ans.push_back(cur);
            return;
        }

        for(int i = start; i < arr.size(); i++) {

            if(i > start && arr[i] == arr[i-1])
                continue;

            if(arr[i] > target)
                break;

            cur.push_back(arr[i]);

            solve(arr,
                  target - arr[i],
                  i + 1,
                  cur,
                  ans);

            cur.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates,
                                        int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> cur;

        solve(candidates, target, 0, cur, ans);

        return ans;
    }
};
