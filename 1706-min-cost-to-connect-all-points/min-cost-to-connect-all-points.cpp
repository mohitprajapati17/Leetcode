class DisjointSet {
private:
    vector<int> parent, size;

public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int node) {
        if (parent[node] == node) return node;
        return parent[node] = find(parent[node]); // Path compression
    }

    void unionBySize(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU == rootV) return;
        if (size[rootU] < size[rootV]) {
            parent[rootU] = rootV;
            size[rootV] += size[rootU];
        } else {
            parent[rootV] = rootU;
            size[rootU] += size[rootV];
        }
    }
};



class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int v=points.size();
        vector<pair<int,pair<int,int>>> adj(v);
        for(int i=0;i<v;i++){
            for(int j=i+1;j<v;j++){
                int x1=points[i][0];
                int  y1=points[i][1];
                int x2=points[j][0];
                int y2=points[j][1];
                int w=abs(x1-x2)+abs(y1-y2);
                adj.push_back({w,{i,j}});
            }
        }

        sort(adj.begin(),adj.end());
        int ans=0;
        DisjointSet ds(v);
        for(auto & it: adj){
            int w=it.first;
            int u=it.second.first;
            int v=it.second.second;
            if(ds.find(u)!=ds.find(v)){
                ans+=w;
                ds.unionBySize(u,v);
            }
        }

        return ans;
    }
};