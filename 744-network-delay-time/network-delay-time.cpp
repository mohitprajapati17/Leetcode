class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>> adj(n + 1);

        for (auto &e : times)
            adj[e[0]].push_back({e[1], e[2]});

        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;

        vector<int> dist(n + 1, INT_MAX);

        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {

            auto [d, node] = pq.top();
            pq.pop();

            if (d > dist[node])
                continue;

            for (auto &[nei, wt] : adj[node]) {

                if (dist[node] + wt < dist[nei]) {

                    dist[nei] = dist[node] + wt;
                    pq.push({dist[nei], nei});
                }
            }
        }

        int ans = 0;

        for (int i = 1; i <= n; i++) {

            if (dist[i] == INT_MAX)
                return -1;

            ans = max(ans, dist[i]);
        }

        return ans;
    }
};