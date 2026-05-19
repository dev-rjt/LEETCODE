class Solution {
public:

    long long power(long long a, int k, long long limit) {
        long long res = 1;

        for(int i = 0; i < k; i++) {
            if(a != 0 && res > limit / a)
                return limit + 1;

            res *= a;
        }

        return res;
    }

    long long kthRoot(long long n, int k) {
        if(n < 0) return 0;

        long long low = 0, high = 1e9;
        long long ans = 0;

        while(low <= high) {
            long long mid = (low + high) / 2;

            if(power(mid, k, n) <= n) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }

    int countKthRoots(int l, int r, int k) {
        if(l == 0)
            return kthRoot(r, k) + 1; // include 0^k

        return kthRoot(r, k) - kthRoot(l - 1, k);
    }
};
