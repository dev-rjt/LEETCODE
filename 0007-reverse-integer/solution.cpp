class Solution {
public:
    int reverse(int x) {
        long long rev = 0;

        while (x != 0) {
            int digit = x % 10;
            rev = rev * 10 + digit;

            // \U0001f50d Check for overflow BEFORE returning
            if (rev > INT32_MAX || rev < INT32_MIN)
                return 0;

            x /= 10;
        }

        return static_cast<int>(rev);
    }
};

