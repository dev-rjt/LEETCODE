class Solution {
public:
    int subarraysWithAtmostKDistinct(vector<int> &nums, int k){
        int left = 0;
        int ans = 0;
        unordered_map<int,int> freq;
        int uniques = 0;

        for(int right=0;right<nums.size();right++){
            freq[nums[right]]++;
            if(freq[nums[right]]==1) uniques++;

            while(left<=right && uniques>k){
                freq[nums[left]]--;
                if(freq[nums[left]]==0) uniques--;
                left++;
            }

            ans+=right-left+1;
        }
        // cout << ans << endl;
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarraysWithAtmostKDistinct(nums,k) - 
               subarraysWithAtmostKDistinct(nums,k-1);
    }
};
