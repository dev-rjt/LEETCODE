class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();
        int zero=0;
        int product = 1;
        int x;

        vector <int> a(n,0);

        for(int i=0;i<n;i++) {
            if(nums[i]==0){
                zero++;
                x=i;
            }

            else {
                product = product*nums[i];
            }
        }

        if(zero==0) {
            for(int i=0;i<n;i++) {
                a[i] = product/nums[i];
            }

            return a;
        }

        else if(zero==1) {
            a[x] = product;
            return a;
        }

        else {
            return a;
        }
        
    }
};
