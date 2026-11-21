class Solution {
public:
    vector<vector<int>> adj;
    vector<int> ans;
    vector<int> last = vector<int>(26, -1);

    void dfs(int node, string& s) {
        int c = s[node] - 'a';

        int prev = last[c];

        last[c] = node;

        for (int child : adj[node]) {
            dfs(child, s);
        }

        ans[node] = 1;

        for (int child : adj[node]) {
            ans[node] += ans[child];
        }

        last[c] = prev;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        adj.assign(n, {});
        ans.assign(n, 0);

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> newParent = parent;

        function<void(int)> findParents = [&](int node) {
            int c = s[node] - 'a';

            if (last[c] != -1) {
                newParent[node] = last[c];
            }

            int prev = last[c];
            last[c] = node;

            for (int child : adj[node]) {
                findParents(child);
            }

            last[c] = prev;
        };

        findParents(0);

        adj.assign(n, {});

        for (int i = 1; i < n; i++) {
            adj[newParent[i]].push_back(i);
        }

        fill(last.begin(), last.end(), -1);

        dfs(0, s);

        return ans;
    }
};