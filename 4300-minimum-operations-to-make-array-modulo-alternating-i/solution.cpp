class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> evenCost(k, 0), oddCost(k, 0);


        for (int i = 0; i < n; i++) {
            int cur = nums[i] % k;

            for (int r = 0; r < k; r++) {
                int cost = min((cur - r + k) % k,(r - cur + k) % k);

                if (i % 2 == 0)
                    evenCost[r] += cost;
                else
                    oddCost[r] += cost;
            }
        }

        int ans = INT_MAX;

        for (int x = 0; x < k; x++) {
            for (int y = 0; y < k; y++) {
                if (x == y) continue;

                ans = min(ans, evenCost[x] + oddCost[y]);
            }
        }

        return ans;
    }
};
