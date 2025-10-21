class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        int x = n-(k%n);
        

        int l = 0;
        int r = x-1;

        while(l<r) {
            swap(nums[l],nums[r]);
            l++;
            r--;
        }

        l=x;
        r=n-1;

        while(l<r) {
            swap(nums[l],nums[r]);
            l++;
            r--;
        }

        l=0;
        r=n-1;

        while(l<r) {
            swap(nums[l],nums[r]);
            l++;
            r--;
        }

    }
};
