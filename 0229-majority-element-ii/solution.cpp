class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int mini = nums.size()/3 + 1;
        
        unordered_map <int,int> freq;
        vector<int> ans;
        
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        
        for(int i=0;i<nums.size();i++){
            if(freq[nums[i]]>=mini){
                ans.push_back(nums[i]);
                freq[nums[i]] = -1;
            }
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};
