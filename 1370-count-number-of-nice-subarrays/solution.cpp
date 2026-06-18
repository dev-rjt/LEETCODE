class Solution {
public:
    int max_KOdd_Subarrays(vector<int> &nums,int k){
        int ans = 0;
        int odd = 0;
        int left = 0;

        for(int right=0;right<nums.size();right++){
            if(nums[right]%2) odd++;

            while(odd>k){
                if(nums[left]%2) odd--;
                left++;
            }

            ans+=right-left+1;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return max_KOdd_Subarrays(nums,k) - max_KOdd_Subarrays(nums,k-1);
    }
};
