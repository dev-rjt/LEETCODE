class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n, 0);

        // difference array apply
        for (int i = 0; i < bookings.size(); i++) {
            int l = bookings[i][0] - 1;
            int r = bookings[i][1] - 1;
            int seats = bookings[i][2];

            ans[l] += seats;
            if (r + 1 < n) ans[r + 1] -= seats;
        }

        // prefix sum
        for (int i = 1; i < n; i++) {
            ans[i] += ans[i - 1];
        }

        return ans;
    }
};

