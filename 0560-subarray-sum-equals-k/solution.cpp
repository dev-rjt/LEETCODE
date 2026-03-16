class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        freq[0] = 1;

        int sum = 0;
        int ans = 0;

        for(int i=0;i<nums.size();i++){
            sum+=nums[i];

            if(freq.count(sum-k)) ans+=freq[sum-k];

            freq[sum]++;

        }

        return ans;
    }
};
