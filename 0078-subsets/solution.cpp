class Solution {
public:

    void include(vector<int> &nums,vector<int> &subset,int index,int len,int n,vector<vector<int>> &a) {
        if(index==n) {
            a.push_back(subset);
            return; 
        }

        subset.push_back(nums[index]);
        include(nums,subset,index+1,len+1,n,a);
        subset.pop_back();
        include(nums,subset,index+1,len,n,a);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> subset;
        vector<vector<int>> a;
        include(nums,subset,0,0,n,a);

        return a;
    }
};
