class Solution {
public:
    vector<vector<int>> adj;
    vector<int> ans, last;

    void findNewParent(int node, string& s, vector<int>& np) {
        int c = s[node] - 'a';

        int prev = last[c];

        if (prev != -1) np[node] = prev;

        last[c] = node;

        for (int child : adj[node]) {
            findNewParent(child, s, np);
        }

        last[c] = prev;
    }

    int dfs(int node) {
        int sz = 1;

        for (int child : adj[node]) {
            sz += dfs(child);
        }

        return ans[node] = sz;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        adj.assign(n, {});
        ans.assign(n, 0);
        last.assign(26, -1);

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> np = parent;

        findNewParent(0, s, np);

        adj.assign(n, {});

        for (int i = 1; i < n; i++) {
            adj[np[i]].push_back(i);
        }

        dfs(0);

        return ans;
    }
};