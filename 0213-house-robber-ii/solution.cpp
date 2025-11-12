class Solution {
public:

    int solve(vector<int> nums) {

        int n = nums.size();
        if(n==0) return 0;;

        int prev1 = 0;
        int prev2 = nums[0];

        for(int i=1;i<n;i++) {
            int include = prev1 + nums[i];
            int exclude = prev2 + 0;

            int ans = max(include,exclude);
            prev1 = prev2;
            prev2 = ans;

        }

        return prev2;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n==1) {
            return nums[0];
        }

        vector<int> first,second;

        for(int i=0;i<n;i++) {
            if(i!=n-1) first.push_back(nums[i]);
            if(i!=0) second.push_back(nums[i]);
        }

        return max(solve(first),solve(second));
    }
};
