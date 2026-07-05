class Solution {
public:
    long long getSum(vector<int>& nums) {
        int n = nums.size();

        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + nums[i];

        long long ans = 0;

        vector<int> d1(n);
        int l = 0, r = -1;
        for (int i = 0; i < n; i++) {
            int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
            while (i - k >= 0 && i + k < n && nums[i - k] == nums[i + k])
                k++;
            d1[i] = k;

            int L = i - k + 1;
            int R = i + k - 1;
            ans = max(ans, pref[R + 1] - pref[L]);

            if (i + k - 1 > r) {
                l = i - k + 1;
                r = i + k - 1;
            }
        }

        // d2[i] = radius of longest even palindrome centered between i-1 and i
        vector<int> d2(n);
        l = 0;
        r = -1;
        for (int i = 0; i < n; i++) {
            int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
            while (i - k - 1 >= 0 && i + k < n &&
                   nums[i - k - 1] == nums[i + k])
                k++;
            d2[i] = k;

            if (k > 0) {
                int L = i - k;
                int R = i + k - 1;
                ans = max(ans, pref[R + 1] - pref[L]);
            }

            if (i + k - 1 > r) {
                l = i - k;
                r = i + k - 1;
            }
        }

        return ans;
    }
};
