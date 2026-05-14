class Solution {
public:
    bool isGood(vector<int>& nums) {
        int size = nums.size();
        unordered_map <int,int> freq;

        for(int i=0;i<size;i++){
            freq[nums[i]]++;
        }

        if(freq[size-1]!=2) return false;

        for(int i=1;i<=size-2;i++){
            if(freq[i]!=1) return false;
        }
        return true;
    }
};
