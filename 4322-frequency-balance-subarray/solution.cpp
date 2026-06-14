class Solution {
public:
    int getLength(vector<int>& a) {
        int n = a.size(), ans = 1;
        for (int i = 0; i < n; i++) {
            map<int, int> mp;      // frequency of each value
            vector<int> fq(n + 1); // count of frequencies
            int mx = 0; // maximum frequency
            int s = 0;  // number of values having frequency mx
            for (int j = i; j < n; j++) {
                if (mp[a[j]])
                    fq[mp[a[j]]]--; // remove old frequency
                mp[a[j]]++;
                fq[mp[a[j]]]++; // add new frequency
                if (mp[a[j]] > mx) {
                    mx = mp[a[j]];
                    s = 1; // new maximum frequency found
                }
                else if (mp[a[j]] == mx) {
                    s++; // another value reaches maximum frequency
                }
                int distinct = mp.size();
                // only one distinct value
                if (distinct == 1) {
                    ans = max(ans, j - i + 1);
                }
                // max frequency must be twice every other frequency
                else if (mx % 2 == 0 &&
                         s < distinct &&
                         fq[mx / 2] == distinct - s) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};
