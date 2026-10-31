class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges,
                     string labels, int k) {

        vector<vector<pair<int,int>>> adj(n);

        for (auto &it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        // dist[node][consecutive_count]
        vector<vector<int>> dist(n, vector<int>(k + 1, INT_MAX));

        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {

            auto [sum, node, cons] = pq.top();
            pq.pop();

            if (sum != dist[node][cons])
                continue;

            if (node == n - 1)
                return sum;

            for (auto &it : adj[node]) {

                int adjnode = it.first;
                int weight = it.second;

                int newCons;

                if (labels[node] == labels[adjnode])
                    newCons = cons + 1;
                else
                    newCons = 1;

                if (newCons > k)
                    continue;

                if (sum + weight < dist[adjnode][newCons]) {

                    dist[adjnode][newCons] = sum + weight;

                    pq.push({
                        sum + weight,
                        adjnode,
                        newCons
                    });
                }
            }
        }

        return -1;
    }
};