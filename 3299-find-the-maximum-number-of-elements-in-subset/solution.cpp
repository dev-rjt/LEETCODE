class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map <long long,int> freq;

        for(auto i:nums) freq[i] +=1;

        int ans = (freq[1]%2) ? freq[1] : max(1,freq[1]-1);

        for(auto i: freq){
            if(i.first==1) continue;

            int res = 0;
            long long x = i.first;

            for(;freq.contains(x) && freq[x]>1; x*=x){
                res+=2;
            }

            ans = max(ans,res+(freq.contains(x) ? 1:-1));
        }

        return ans;
    }
};
