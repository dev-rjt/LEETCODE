class Solution {
public:
    void solve(vector<int> &nums,int i,vector<int> res,vector<vector<int>> &ans){
        if(i>=nums.size()){
            ans.push_back(res);
            return;
        };

        solve(nums,i+1,res,ans);

        res.push_back(nums[i]);
        solve(nums,i+1,res,ans);
        res.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(nums,0,{},ans);
        return ans;
    }
};
