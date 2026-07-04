class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int i = 0;
        int j = i+k;

        int sum = 0;
        int num = 0;

        while(j<nums.size()){
            num = max(num,nums[i]);
            sum = max(sum,num+nums[j]);
            i++;
            j++;
        }

        return sum;
    }
};
