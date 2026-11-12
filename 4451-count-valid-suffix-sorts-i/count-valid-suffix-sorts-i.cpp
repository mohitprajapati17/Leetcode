
class Solution {
public:
    int countSuffix(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        int ans = 0;
        int index = n;

        // Find first mismatch
        for (int i = 0; i < n; i++) {
            if (nums[i] != target[i]) {
                index = i;
                break;
            }
        }

        unordered_map<int, int> mp;
        bool sorted = true;

        for (int i = n - 1; i >= 0; i--) {

            // Check non-increasing order of target suffix
            if (i < n - 1 && target[i] < target[i + 1]) {
                sorted = false;
            }

            mp[nums[i]]++;
            mp[target[i]]--;

            // Remove zero-frequency differences
            if (mp[nums[i]] == 0)
                mp.erase(nums[i]);

            if (mp.find(target[i]) != mp.end() &&
                mp[target[i]] == 0)
                mp.erase(target[i]);

            if (mp.empty() && i <= index && sorted) {
                ans++;
            }
        }

        return ans;
    }
};
