class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int ans = 0;
        vector<pair<int,int>> range;

        for(auto i:nums){
            int mini = 11;
            int maxi = -1;

            int num = i;

            while(num){
                int digit = num%10;
                num/=10;
                mini = min(mini,digit);
                maxi = max(maxi,digit);
            }
            ans = max(maxi-mini,ans);
            range.push_back({i,maxi-mini});
        }
        int sum = 0;
        
        for(auto i:range){
            if(i.second==ans) sum+=i.first;
        }
        return sum;
    }
};
