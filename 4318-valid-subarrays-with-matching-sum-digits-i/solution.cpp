class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            long long sum = 0;
            for(int j=i;j<nums.size();j++){
                sum+=nums[j];
                long long res = sum;
                int last = sum%10;
                int first = 0;
                while(res){
                    first = res;
                    res = res/10;
                }
                if(first==x && last==x) ans++;
            }
        }
        return ans;
    }
};
