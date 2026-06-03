class Solution {
public:
    void solve(vector<int> &nums,int i,vector<int> res,vector<vector<int>> &ans){
        ans.push_back(res);

        for(int j=i;j<nums.size();j++){

            if(j>i && nums[j]==nums[j-1]){
                continue;
            }
            
            res.push_back(nums[j]);
            solve(nums,j+1,res,ans);
            res.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        solve(nums,0,{},ans);
        return ans;
    }
};
