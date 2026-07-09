class DisjointSet{
    vector<int>rank,parent;
     public :DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);

        for(int i=0;i<=n;i++ ) parent[i]=i;
     }

    int  findUparent(int node){
        if(parent[node]==node) return node;
        else  return  parent[node]=findUparent(parent[node]);
    }
    void  UnionByRank(int  u,int  v){
        int ulp_v=findUparent(v);
        int ulp_u=findUparent(u);

        if(parent[u]==parent[v]) return;
        else{
            if(rank[ulp_v]<rank[ulp_u]){

                parent[ulp_v]=ulp_u;
            }
            else if(rank[ulp_u]<rank[ulp_v]){
                parent[ulp_u]=ulp_v;
            }
            else{
                parent[ulp_v]=ulp_u;
                rank[ulp_u]++;
            }
        }
    }

    int connected(){

        int ans=0;
        for(int  i=0;i<parent.size()-1;i++){
            if(parent[i]==i) ans++;
        }
        return ans;
    }

    
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        DisjointSet ds(n);
        for(int  i=0;i<isConnected.size();i++){
            for(int  j=0;j<isConnected[i].size();j++){
                if(isConnected[i][j]==1){
                    ds.UnionByRank(i,j);
                    
                }
            }
            
         }
         return ds.connected();
    }
};