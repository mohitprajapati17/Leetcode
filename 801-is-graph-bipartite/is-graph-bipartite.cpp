class Solution {
public:
    bool bfs(int i,vector<int> &vis,queue<pair<int,int>> &q,vector<vector<int>>&graph){
        int n=graph.size();
        vis[i]=0;
        q.push({i,0});

        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int node=it.first;

            int c=it.second;

            for(auto & i:graph[node]){
                if(vis[i]==-1){
                    cout<<!c<<endl;
                    vis[i]=!c;
                      q.push({i,!c});
                }
                else if(vis[i]==c) return false;
               
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {

        int n=graph.size();
        queue<pair<int,int>> q;
        vector<int> vis(n,-1);

        for(int  i=0;i<n;i++){
            if(vis[i]==-1){
                bool f= bfs(i,vis,q,graph);
                if(f==false) return false;

            }
        }
        return true;

       
    }
};