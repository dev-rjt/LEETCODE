class Solution {
public:
    int divisibleGame(vector<int>& nums) {
    
        pair<int,int> ans = {-1,2};

        set<int> divisors;

         for (int x : nums) {
            for (int d = 2; 1LL * d * d <= x; d++) {
                if (x % d == 0) {
                    divisors.insert(d);
                    divisors.insert(x / d);
                }
            }
            if (x >= 2) divisors.insert(x);
        }

        for(auto k: divisors){
            int currSum = 0;
            int maxSum = INT_MIN;

            for(int i=0;i<nums.size();i++){
                int num = nums[i]%k ? -1 : 1;
                currSum+=nums[i]*num;
                maxSum = max(maxSum,currSum);
                if(currSum<0) currSum=0;
            }

            if(maxSum>ans.first){
                ans.first = maxSum;
                ans.second = k;
            }
        }

        cout << ans.first << " " << ans.second << endl;
        long long mod = 1e9+7;
        long long res =  (1LL*ans.first*ans.second);
        return (res+mod)%mod;
    }
};
