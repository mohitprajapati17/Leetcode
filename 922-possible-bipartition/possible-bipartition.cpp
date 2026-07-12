class Solution {
public:
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>adj(n+1);
        for(int i=0;i<dislikes.size();i++){
             adj[dislikes[i][0]].push_back(dislikes[i][1]);
             adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }

        queue<pair<int,int>> q;
        vector<int> color(n+1,-1);
        

        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                q.push({i,0});
                while(!q.empty()){
                    int node =q.front().first;
                    int  c=q.front().second;
                    q.pop();

                    
                    for(auto & it: adj[node]){
                        if(color[it]==-1){
                            color[it]=!c;
                            q.push({it,!c});
                        }
                        else {
                            if(color[it]==c) return false;
                        }
                    }
                }
            }
        }
        return true;

    }
};