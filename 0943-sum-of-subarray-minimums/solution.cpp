class Solution {
public:
    vector<int> nse(vector<int>& arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=n-1;i>=0;i--) {
            while(s.top()!=-1 && arr[s.top()] >= arr[i])
                s.pop();

            ans[i] = s.top();
            s.push(i);
        }

        return ans;
    }

    vector<int> pse(vector<int>& arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=0;i<n;i++) {
            while(s.top()!=-1 && arr[s.top()] > arr[i])
                s.pop();

            ans[i] = s.top();
            s.push(i);
        }

        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> pre = pse(arr, n);
        vector<int> next = nse(arr, n);

        long long ans = 0;
        const int mod = 1e9 + 7;

        for(int i=0;i<n;i++) {
            long long left = i - pre[i];

            long long right =
                (next[i] == -1 ? n : next[i]) - i;

            long long contribution =
                ((left * right) % mod * arr[i]) % mod;

            ans = (ans + contribution) % mod;
        }

        return ans;
    }
};
