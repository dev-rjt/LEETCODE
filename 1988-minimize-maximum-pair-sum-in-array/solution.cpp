class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int maxi = INT_MIN;

        int i=0,j=nums.size()-1;

        while(j>i){
            maxi = max(nums[i]+nums[j],maxi);
            i++;
            j--;
        }

        return maxi;
    }
};
