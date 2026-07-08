class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }

        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});

        int ans=INT_MAX;
        vector<int> dist(n,INT_MAX);

        dist[src]=0;

        while(!q.empty()){
            auto &  it= q.front();

            int stops =it.first;
            int node =it.second.first;
            int cost =it.second.second;
            q.pop();
            if(stops>k) continue;


            for(auto& iter:adj[node]){
                int w=iter.second;
                int adj_node=iter.first;
                if(w+cost<dist[adj_node]&&stops<=k){
                    dist[adj_node]=w+cost;
                    q.push({stops+1,{adj_node,dist[adj_node]}});
                }
            }


        }
        if(dist[dst]==INT_MAX)  return -1;
        return  dist[dst];
    }
};