class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int left = 0;
        int ans= 0;
        int sum = 0;
        int zeroes = 0;

        for(int right=0;right<nums.size();right++){
            if(nums[right]==1) sum+=1;

            if(sum==goal){
                while(left<right && nums[left]==0){
                    left++;
                    zeroes++;
                }
                ans += 1+zeroes;
            }
            else if(sum>goal){
                while(sum>goal){
                    sum-=nums[left];
                    left++;
                }
                zeroes = 0;
                if(right>=left){
                    while(left<right && nums[left]==0){
                        left++;
                        zeroes++;
                    }
                    ans += 1+zeroes;
                }
            }
        }
        cout << ans << endl;
        cout << left << endl;
        while(left<nums.size()-1 && sum==goal){
            sum-=nums[left];
            left++;
            if(sum==goal) ans+=1;
        }
        return ans;
    }
};
