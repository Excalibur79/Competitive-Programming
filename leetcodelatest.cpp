class Solution {
   public:
    map<string, int> dp;

    string generateKey(int x, int y, int z) {
        return to_string(x) + to_string(y) + to_string(z);
    }

    int recur(vector<vector<int>> &costs, int n, int a, int b) {
        if (n == 0) return 0;
        string key = generateKey(n, a, b);
        string newKey;
        if (dp.find(key) != dp.end()) return dp[key];
        int ans1 = INT_MAX, ans2 = INT_MAX;
        if (a < costs.size() / 2) {
            newKey = generateKey(n - 1, 1 + a, b);
            dp[newKey] = recur(costs, n - 1, 1 + a, b);
            ans1 = costs[n - 1][0] + dp[newKey];
        }
        if (b < costs.size() / 2) {
            newKey = generateKey(n - 1, a, b + 1);
            dp[newKey] = recur(costs, n - 1, a, 1 + b);
            ans2 = costs[n - 1][1] + dp[newKey];
        }

        return dp[key] = min(ans1, ans2);
    }

    int twoCitySchedCost(vector<vector<int>> &costs) {
        int ans = recur(costs, costs.size(), 0, 0);
        return ans;
    }
};