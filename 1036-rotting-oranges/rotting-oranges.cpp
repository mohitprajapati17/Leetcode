class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>> q;
        int  n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if(grid[i][j]==2){
                   q.push({i,{j,0}});
               }
            }
        }
        
        int  time =0;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int r=it.first;
            int c=it.second.first;
            int t=it.second.second;
            time=t;

            vector<int> dr={-1,+1,0,0},dc={0,0,-1,+1};
      
            for(int it=0;it<4;it++){
                int new_r=dr[it]+r;
                int new_c=dc[it]+c;
                if(new_r>=0&&new_r<n&&new_c>=0&&new_c<m&&grid[new_r][new_c]==1){
                    grid[new_r][new_c]=2;
                    q.push({new_r,{new_c,t+1}});
                }
            }
        }
        for(int i=0;i<n;i++ ){
            for(int j=0;j<m;j++){
                cout<<grid[i][j]<<" ";
                if(grid[i][j]==1) return -1;
            }
            cout<<endl;
        }
        return time;
    }
};
