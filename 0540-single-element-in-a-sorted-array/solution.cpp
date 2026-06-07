class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;

        while(left<=right){
            int mid = (left+right)/2;

            if(mid%2){
                if(mid-1>=0 && nums[mid-1]==nums[mid]){
                   left = mid+1; 
                }

                else if(mid+1<nums.size() && nums[mid]==nums[mid+1]){
                    right = mid-1;
                }
                else{
                    return nums[mid];
                }
            }
            else{
                if(mid-1>=0 && nums[mid-1]==nums[mid]){
                   right = mid-1;
                }

                else if(mid+1<nums.size() && nums[mid]==nums[mid+1]){
                    left = mid+1;
                }
                else{
                    return nums[mid];
                }
            }
        }

        return -1;
    }
};
