class SegmentTree {
public:
    int n;
    vector<int> st;

    SegmentTree(int n) : n(n) {
        st.assign(4 * n, 0);
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            st[node] = val;
            return;
        }

        int mid = (l + r) >> 1;

        if (idx <= mid)
            update(node * 2, l, mid, idx, val);
        else
            update(node * 2 + 1, mid + 1, r, idx, val);

        st[node] = max(st[node * 2], st[node * 2 + 1]);
    }

    void update(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return 0;

        if (ql <= l && r <= qr)
            return st[node];

        int mid = (l + r) >> 1;

        return max(
            query(node * 2, l, mid, ql, qr),
            query(node * 2 + 1, mid + 1, r, ql, qr)
        );
    }

    int query(int l, int r) {
        if (l > r) return 0;
        return query(1, 0, n - 1, l, r);
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {

        vector<int> coords{0};

        for (auto &q : queries) {
            coords.push_back(q[1]);
        }

        sort(coords.begin(), coords.end());
        coords.erase(unique(coords.begin(), coords.end()), coords.end());

        int m = coords.size();

        auto getId = [&](int x) {
            return lower_bound(coords.begin(), coords.end(), x) - coords.begin();
        };

        set<int> obstacles;

        for (auto &q : queries) {
            if (q[0] == 1)
                obstacles.insert(q[1]);
        }

        obstacles.insert(0);

        SegmentTree seg(m);

        vector<int> pos(obstacles.begin(), obstacles.end());

        for (int i = 1; i < (int)pos.size(); i++) {
            seg.update(
                getId(pos[i]),
                pos[i] - pos[i - 1]
            );
        }

        vector<bool> ans;

        for (int i = (int)queries.size() - 1; i >= 0; i--) {

            auto &q = queries[i];

            if (q[0] == 2) {

                int x = q[1];
                int sz = q[2];

                auto it = obstacles.upper_bound(x);

                int mx = 0;

                if (it != obstacles.begin()) {

                    auto prv = prev(it);

                    int p = *prv;

                    mx = seg.query(0, getId(p));

                    mx = max(mx, x - p);
                }

                ans.push_back(mx >= sz);

            } else {

                int x = q[1];

                auto it = obstacles.find(x);

                auto L = prev(it);
                auto R = next(it);

                if (R != obstacles.end()) {
                    seg.update(
                        getId(*R),
                        *R - *L
                    );
                }

                obstacles.erase(it);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
