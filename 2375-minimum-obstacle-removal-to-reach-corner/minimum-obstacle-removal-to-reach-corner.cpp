class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
       priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
       
        pq.push({0,{0,0}});
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,-1));
       
       while(!pq.empty()){
           int cost=pq.top().first;
           int r=pq.top().second.first;
           int c=pq.top().second.second;
           pq.pop();
           if(vis[r][c]==1) continue;
           if(r==n-1&&c==m-1) return cost;
           vis[r][c]=1;
           vector<int> dr={-1,+1,0,0},dc={0,0,-1,+1};
           for(int i=0;i<4;i++){
               int new_r =dr[i]+r;
               int new_c=dc[i]+c;
               if(new_r>=0&&new_c>=0&&new_c<m&&new_r<n){
                   if(vis[new_r][new_c]==-1){
                       if(grid[new_r][new_c]==1){
                         pq.push({cost+1,{new_r,new_c}});
                       }
                       else pq.push({cost,{new_r,new_c}});
                   }
               }
           }


       }

       return -1;



    }
};