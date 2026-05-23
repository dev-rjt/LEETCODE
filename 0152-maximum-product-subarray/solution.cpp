class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curr_min = nums[0];
        int curr_max = nums[0];
        int maxpro = nums[0];
        
        for(int i=1;i<nums.size();i++){
            int temp_min = curr_min;
            int temp_max = curr_max;
            
            if(nums[i]>=0){
                curr_min = min(nums[i],temp_min*nums[i]);
                curr_max = max(nums[i],temp_max*nums[i]);
                maxpro = max(curr_max,maxpro);
            }
            
           
            else{
                curr_min = min(nums[i],temp_max*nums[i]);
                curr_max = max(nums[i],temp_min*nums[i]);
                 maxpro = max(curr_max,maxpro);
            }
        }
        
        return maxpro;
    }
};
