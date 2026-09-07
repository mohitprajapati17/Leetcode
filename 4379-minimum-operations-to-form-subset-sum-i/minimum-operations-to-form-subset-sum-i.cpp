class Solution {
public:
    struct State {
        int target;
        int cost;
    };

    int minOperations(vector<int>& nums, int sum) {
        int n = nums.size();

        const int INF = INT_MAX;
        vector<int> dp(sum + 1, INF);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            int cur = nums[i];
            vector<State> cost;

            int ops = 0;

            // Multiplication
            while (cur <= sum) {
                cost.push_back({cur, ops});
                cur <<= 1;
                ops++;
            }

            // Division
            cur = nums[i];
            ops = 0;
            while (cur >= 1) {
                if (cur <= sum)
                    cost.push_back({cur, ops});
                cur >>= 1;
                ops++;
            }

            vector<int> next = dp;

            for (int s = 0; s <= sum; s++) {
                if (dp[s] == INF)
                    continue;

                for (auto &c : cost) {
                    int tar = c.target;
                    int op = c.cost;

                    if (s + tar <= sum) {
                        next[s + tar] = min(next[s + tar], dp[s] + op);
                    }
                }
            }

            dp = next;
        }

        return dp[sum] == INF ? -1 : dp[sum];
    }
};