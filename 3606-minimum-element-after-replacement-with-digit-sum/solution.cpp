class Solution {
public:
    int minElement(vector<int>& nums) {
        int mini = INT_MAX;
        for(int i=0;i<nums.size();i++){
            int sum = 0;
            while(nums[i]){
                sum+=nums[i]%10;
                nums[i]/=10;
            }
            mini = min(mini,sum);
        }

        return mini;
    }
};
