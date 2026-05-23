class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int i = 0;
        int j = nums.size()-1;
        int ans = 0;

        while(i<j){
            if(nums[j]==0){
                j--;
            }

            else if(nums[i]==0){
                ans++;
                i++;
                j--;
            }

            else{
                i++;
            }
        }

        return ans;
    }
};
