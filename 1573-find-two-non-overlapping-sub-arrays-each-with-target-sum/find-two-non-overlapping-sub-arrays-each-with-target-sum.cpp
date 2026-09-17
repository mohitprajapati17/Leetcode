class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        vector<pair<int, int>> intervals;

        int n = arr.size();
        int left = 0;
        int sum = 0;

        // Find all subarrays with sum = target
        for (int right = 0; right < n; right++) {
            sum += arr[right];

            while (sum > target) {
                sum -= arr[left++];
            }

            if (sum == target) {
                intervals.push_back({left, right});
            }
        }

        int m = intervals.size();
        if (m < 2) return -1;

        // suffixMin[i] = minimum length among intervals[i...m-1]
        vector<int> suffixMin(m);

        suffixMin[m - 1] =
            intervals[m - 1].second - intervals[m - 1].first + 1;

        for (int i = m - 2; i >= 0; i--) {
            int len = intervals[i].second - intervals[i].first + 1;
            suffixMin[i] = min(len, suffixMin[i + 1]);
        }

        int ans = INT_MAX;

        for (int i = 0; i < m; i++) {
            int end = intervals[i].second;
            int len = end - intervals[i].first + 1;

            // First interval whose start > current end
            auto it = upper_bound(
                intervals.begin(),
                intervals.end(),
                make_pair(end, INT_MAX)
            );

            if (it != intervals.end()) {
                int idx = it - intervals.begin();
                ans = min(ans, len + suffixMin[idx]);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};