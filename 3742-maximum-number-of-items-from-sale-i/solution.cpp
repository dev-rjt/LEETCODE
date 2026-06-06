class Solution {
    int min_cost;
    vector<int> values;
    vector<int> costs;
    vector<vector<int>> memo;

    int solve(int idx, int current_budget) {
        if (idx == values.size()) {
            return current_budget / min_cost;
        }

        if (memo[idx][current_budget] != -1) {
            return memo[idx][current_budget];
        }

        int max_items = solve(idx + 1, current_budget);

        if (current_budget >= costs[idx]) {
            int items_if_bought = values[idx] + solve(idx + 1, current_budget - costs[idx]);
            max_items = max(max_items, items_if_bought);
        }

        return memo[idx][current_budget] = max_items;
    }

public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        min_cost = INT_MAX;
        
        values.resize(n, 0);
        costs.resize(n, 0);

        for (int i = 0; i < n; i++) {
            costs[i] = items[i][1];
            min_cost = min(min_cost, costs[i]);

            for (int j = 0; j < n; j++) {
                if (items[j][0] % items[i][0] == 0) {
                    values[i]++;
                }
            }
        }

        memo.assign(n, vector<int>(budget + 1, -1));

        return solve(0, budget);
    }
};
