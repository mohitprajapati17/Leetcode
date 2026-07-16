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
    int removeStones(vector<vector<int>>& stones) {
        int v=stones.size();
        DisjointSet ds(v);
        for(int i=0;i<v;i++){
            for(int j=i+1;j<v;j++){
                if(stones[i][0]==stones[j][0]||stones[i][1]==stones[j][1]){
                      ds.unionBySize(i,j);
                }
            }
        }
        int  ans=0;
        for(int i=0;i<v;i++){
            if(ds.find(i)==i) ans++;
        }
        return v-ans;

    }
};