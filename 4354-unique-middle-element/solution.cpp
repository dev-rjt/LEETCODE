class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size();
        int num = nums[n/2];

        int freq = 0;


        for(auto i:nums){
            if(i==num) freq++;
        }

        if(freq==1) return true;
        return false;
    }
};
