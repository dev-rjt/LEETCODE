class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();

        int x=0;

        for(int i=0;i<n-1;i++) {
            if(nums[i+1]<nums[i]) {
                x++;
            }
        }

        if(x==0 || x==1 && nums[n-1]<=nums[0]) {
            return true;
        }

        else {
            return false;
        }
    }
};
