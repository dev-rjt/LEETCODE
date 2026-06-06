class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> suffix(n,0);
        vector<int> prefix(n,0);

        int sum = 0;

        for(int i=0;i<n;i++){
            sum+=nums[i];
            prefix[i]+=sum;
        }

        sum = 0;

        for(int i=n-1;i>=0;i--){
            sum+=nums[i];
            suffix[i]+=sum;
        }

        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            ans[i] = abs(prefix[i]-suffix[i]);
        }

        return ans;
    }
};
