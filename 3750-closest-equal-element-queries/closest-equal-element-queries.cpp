class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();

        unordered_map<int, vector<int>> pos;

        for (int i = 0; i < n; i++)
            pos[nums[i]].push_back(i);

        vector<int> ans;

        for (int idx : queries) {

            auto &v = pos[nums[idx]];

            if (v.size() == 1) {
                ans.push_back(-1);
                continue;
            }

            int k = lower_bound(v.begin(), v.end(), idx) - v.begin();

            int m = v.size();
            int best = INT_MAX;

            // Previous occurrence (circular)
            int prev = v[(k - 1 + m) % m];
            int d = abs(idx - prev);
            best = min(best, min(d, n - d));

            // Next occurrence (circular)
            int next = v[(k + 1) % m];
            d = abs(idx - next);
            best = min(best, min(d, n - d));

            ans.push_back(best);
        }

        return ans;
    }
};