class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> a;
        vector<int> b;

        for(int i=0;i<nums.size();i++){
            if(nums[i]<pivot) a.push_back(nums[i]);
            else if(nums[i]>pivot) b.push_back(nums[i]);
        }

        int index = 0;

        for(int i=0;i<a.size();i++){
            nums[index++] = a[i];
        }
        for(int i=0;i<(nums.size()-a.size()-b.size());i++) nums[index++] = pivot;
        for(int i=0;i<b.size();i++){
            nums[index++] = b[i];
        }
        return nums;
    }
};
