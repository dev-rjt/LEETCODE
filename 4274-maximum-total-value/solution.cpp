class Solution {
public:
    static constexpr long long MOD = 1000000007LL;

    long long countTerms(vector<int>& value, vector<int>& decay, long long x) {
        long long cnt = 0;

        for (int i = 0; i < value.size(); i++) {
            if (value[i] < x) continue;

            cnt += (value[i] - x) / decay[i] + 1;
        }

        return cnt;
    }

    long long sumTerms(vector<int>& value, vector<int>& decay, long long x) {
        long long sum = 0;

        for (int i = 0; i < value.size(); i++) {
            if (value[i] <= x) continue;

            long long k = (value[i] - (x + 1)) / decay[i] + 1;

            long long last = value[i] - (k - 1) * 1LL * decay[i];

            sum += k * (2LL * value[i] + 2LL * last) / 2;
            sum /= 2;
        }

        return sum;
    }

    int maxTotalValue(vector<int>& value, vector<int>& decay, int m) {
        long long lo = 1, hi = 1e9;

        while (lo <= hi) {
            long long mid = (lo + hi) / 2;

            if (countTerms(value, decay, mid) >= m)
                lo = mid + 1;
            else
                hi = mid - 1;
        }

        long long T = hi;

        long long cntGreater = 0;
        long long ans = 0;

        for (int i = 0; i < value.size(); i++) {
            if (value[i] <= T) continue;

            long long k = (value[i] - (T + 1)) / decay[i] + 1;

            long long last = value[i] - (k - 1) * 1LL * decay[i];

            ans += k * (value[i] + last) / 2;
            cntGreater += k;
        }

        ans += (long long)(m - cntGreater) * T;

        return ans % MOD;
    }
};
