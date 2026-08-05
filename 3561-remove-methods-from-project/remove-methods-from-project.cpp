class Solution {
          
    void dfs(vector<int>&visi,vector<vector<int>>&adj,int i){
        visi[i]=1;
        for(auto &   it: adj[i]){
            if(visi[it]==0){
                dfs(visi,adj,it);
            }
        }
    }

public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int>  vis(n,0);
        // int ans=0;
        vector<vector<int>> adj(n);
        for(auto & it:  invocations){
            adj[it[0]].push_back(it[1]);
        }
        dfs(vis,adj,k);
        vector<int>vis1(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                dfs(vis1,adj,i);
            }
        }
        for(int  i=0;i<n;i++){
            cout<<vis[i]<<" "<<vis1[i]<<endl;
        }
        vector<int> ans;
        bool flag=false;
        for(int  i=0;i<n;i++){
            if(vis[i]==1&&vis1[i]==1){
                flag=true;
            }
        }
        if(flag){
            for(int  i=0;i<n;i++) ans.push_back(i);
           return ans;
        }

        for(int i=0;i<n;i++){
            if(vis[i]==0&&vis1[i]==1){
                 ans.push_back(i);
            }
            
        }
        return  ans;
    }
};